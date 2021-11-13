#include "ezored/dataservices/EZRTodoDataService.hpp"
#include "ezored/core/ApplicationCore.hpp"
#include "ezored/core/ApplicationCoreImpl.hpp"
#include "ezored/helpers/MapHelper.hpp"
#include "ezored/helpers/SimpleStringHelper.hpp"
#include "ezored/helpers/TodoHelper.hpp"
#include "ezored/time/DateTime.hpp"

#include <string>

namespace ezored
{
namespace dataservices
{

using namespace ezored::helpers;
using namespace ezored::domain;
using namespace ezored::time;
using namespace ezored::core;

Todo EZRTodoDataService::bindFromRow(SQLite::Statement &row)
{
    auto todo = TodoHelper::create();

    todo.id = row.getColumn("id").getInt64();
    todo.title = row.getColumn("title").getString();
    todo.body = row.getColumn("body").getString();
    todo.data = MapHelper::fromJsonString(row.getColumn("data"));
    todo.createdAt = DateTime::getDateTimeFromString(row.getColumn("created_at").getString());
    todo.updatedAt = DateTime::getDateTimeFromString(row.getColumn("updated_at").getString());

    if (row.getColumn("done").getInt() == 1)
    {
        todo.done = true;
    }
    else
    {
        todo.done = false;
    }

    return todo;
}

void TodoDataService::truncate()
{
    auto sql = "DELETE FROM todo; VACUUM;";

    auto application = std::static_pointer_cast<ApplicationCoreImpl>(ApplicationCore::shared());
    auto db = application->getDB();

    SQLite::Statement query(*db, sql);

    query.exec();
}

int64_t TodoDataService::insert(const Todo &todo)
{
    auto sql =
        "INSERT INTO todo (title, body, data, done, created_at, updated_at) "
        "VALUES (:title, :body, :data, :done, :created_at, :updated_at)";

    auto application = std::static_pointer_cast<ApplicationCoreImpl>(ApplicationCore::shared());
    auto db = application->getDB();

    SQLite::Statement query(*db, sql);

    query.bind(":title", todo.title);
    query.bind(":body", todo.body);
    query.bind(":data", MapHelper::toJsonString(todo.data));
    query.bind(":done", todo.done);
    query.bind(":created_at", DateTime::getStringFromDateTime(todo.createdAt));
    query.bind(":updated_at", DateTime::getStringFromDateTime(todo.updatedAt));
    query.exec();

    return db->getLastInsertRowid();
}

void TodoDataService::update(int64_t id, const Todo &todo)
{
    auto sql =
        "UPDATE todo SET "
        "title = :title, "
        "body = :body, "
        "data = :data, "
        "done = :done, "
        "updated_at = :updated_at "
        "WHERE id = :id";

    auto application = std::static_pointer_cast<ApplicationCoreImpl>(ApplicationCore::shared());
    auto db = application->getDB();

    SQLite::Statement query(*db, sql);

    query.bind(":id", id);
    query.bind(":title", todo.title);
    query.bind(":body", todo.body);
    query.bind(":data", MapHelper::toJsonString(todo.data));
    query.bind(":done", todo.done);
    query.bind(":updated_at", DateTime::getStringFromDateTime(todo.updatedAt));
    query.exec();
}

int64_t TodoDataService::add(const Todo &todo)
{
    auto found = findById(todo.id);

    if (found.id > 0)
    {
        update(found.id, todo);
        return found.id;
    }
    else
    {
        return insert(todo);
    }
}

void TodoDataService::removeById(int64_t id)
{
    auto sql = "DELETE FROM todo WHERE id = :id";

    auto application = std::static_pointer_cast<ApplicationCoreImpl>(ApplicationCore::shared());
    auto db = application->getDB();

    SQLite::Statement query(*db, sql);

    query.bind(":id", id);
    query.exec();
}

std::vector<Todo> TodoDataService::findAllOrderByCreatedAtDesc()
{
    auto sql = "SELECT * FROM todo ORDER BY created_at DESC";

    auto application = std::static_pointer_cast<ApplicationCoreImpl>(ApplicationCore::shared());
    auto db = application->getDB();

    SQLite::Statement query(*db, sql);

    auto list = std::vector<Todo>{};

    while (query.executeStep())
    {
        auto todo = EZRTodoDataService::bindFromRow(query);
        list.push_back(todo);
    }

    return list;
}

std::vector<Todo> TodoDataService::findByTitle(const std::string &title)
{
    auto hasTitle = false;

    auto sql = std::string("SELECT * FROM todo WHERE 1=1");

    if (title.length() > 0)
    {
        sql = sql + " AND title LIKE :todo_title ";
        hasTitle = true;
    }

    sql = sql + " ORDER BY created_at DESC ";

    auto application = std::static_pointer_cast<ApplicationCoreImpl>(ApplicationCore::shared());
    auto db = application->getDB();

    SQLite::Statement query(*db, sql);

    if (hasTitle)
    {
        query.bind(":todo_title", SimpleStringHelper::format("%%%s%%", title.c_str()));
    }

    auto list = std::vector<Todo>{};

    while (query.executeStep())
    {
        auto todo = EZRTodoDataService::bindFromRow(query);
        list.push_back(todo);
    }

    return list;
}

void TodoDataService::setDoneById(int64_t id, bool done)
{
    auto sql = "UPDATE todo SET done = :done WHERE id = :id";

    auto application = std::static_pointer_cast<ApplicationCoreImpl>(ApplicationCore::shared());
    auto db = application->getDB();

    SQLite::Statement query(*db, sql);

    query.bind(":id", id);
    query.bind(":done", done);
    query.exec();
}

Todo TodoDataService::findById(int64_t id)
{
    auto sql = "SELECT * FROM todo WHERE id = :id LIMIT 1";

    auto application = std::static_pointer_cast<ApplicationCoreImpl>(ApplicationCore::shared());
    auto db = application->getDB();

    SQLite::Statement query(*db, sql);

    query.bind(":id", id);

    while (query.executeStep())
    {
        auto todo = EZRTodoDataService::bindFromRow(query);
        return todo;
    }

    return TodoHelper::create();
}

} // namespace dataservices
} // namespace ezored
