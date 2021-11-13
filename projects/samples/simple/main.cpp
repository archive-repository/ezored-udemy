#include "ezored/core/ApplicationCore.hpp"

#include "ezored/util/Logger.hpp"
#include "ezored/util/LoggerLevel.hpp"
#include "ezored/util/SimpleLoggerPlatformService.hpp"

#include "ezored/net/http/HttpClient.hpp"
#include "ezored/net/http/HttpClientLoggerImpl.hpp"
#include "ezored/net/http/HttpRequest.hpp"
#include "ezored/net/http/HttpResponse.hpp"
#include "ezored/net/http/SimpleHttpClientPlatformService.hpp"

#include "ezored/time/DateTime.hpp"

#include "ezored/io/FileHelper.hpp"
#include "ezored/io/SimpleFileHelperPlatformService.hpp"

#include "ezored/helpers/CustomerHelper.hpp"
#include "ezored/helpers/EnvironmentHelper.hpp"
#include "ezored/helpers/StringHelper.hpp"
#include "ezored/helpers/TodoHelper.hpp"

#include "ezored/data/SharedData.hpp"
#include "ezored/data/SimpleSharedDataPlatformService.hpp"

#include "ezored/domain/DeviceData.hpp"
#include "ezored/domain/InitializationData.hpp"
#include "ezored/domain/Todo.hpp"

#include "ezored/dataservices/TodoDataService.hpp"

#include "ezored/systemservices/CustomerSystemService.hpp"
#include "ezored/systemservices/CustomerSystemServiceLoginData.hpp"

#include <iostream>
#include <memory>

using namespace ezored::util;
using namespace ezored::net::http;
using namespace ezored::time;
using namespace ezored::helpers;
using namespace ezored::io;
using namespace ezored::data;

using namespace ezored::domain;
using namespace ezored::core;
using namespace ezored::dataservices;
using namespace ezored::systemservices;
using namespace ezored::helpers;

int main(int argc, char **argv)
{
    // platform services
    Logger::shared()->setPlatformService(std::make_shared<SimpleLoggerPlatformService>());
    Logger::shared()->setLevel(LoggerLevel::VERBOSE);

    FileHelper::shared()->setPlatformService(std::make_shared<SimpleFileHelperPlatformService>());
    HttpClient::shared()->setPlatformService(std::make_shared<SimpleHttpClientPlatformService>());
    SharedData::shared()->setPlatformService(std::make_shared<SimpleSharedDataPlatformService>());

    // application core
    auto homeDir = FileHelper::join(FileHelper::getHomeDir(), "ezored");
    FileHelper::createDir(homeDir);

    auto initializationData = InitializationData{"com.ezored.sample", "ezored", homeDir, 0, true};
    auto deviceData = DeviceData{"", "", "", "", "", "", "", "", "", 0, 0, 0, "", "", "", ""};

    ApplicationCore::shared()->initialize(initializationData, deviceData);

    // get initialized customer is stored before
    {
        auto customer = ApplicationCore::shared()->getCustomer();
        Logger::i("Current customer ID: " + std::to_string(customer.id) + " - " + customer.name + " - " + customer.token);
        Logger::i("Current customer token: " + CustomerHelper::getToken());
        Logger::i("Current customer is logged: " + std::string((CustomerHelper::isLogged() ? "YES" : "NO")));
    }

    // clear and add TODO items to database
    {
        TodoDataService::truncate();

        // todo 1
        auto todo1 = TodoHelper::create();
        todo1.title = "Title 1";
        todo1.body = "Body 1";
        todo1.done = false;
        todo1.data["key1"] = "value1";

        todo1.id = TodoDataService::add(todo1);

        todo1.done = true;
        TodoDataService::add(todo1);

        TodoDataService::setDoneById(todo1.id, false);

        // todo 2
        auto todo2 = TodoHelper::create();
        todo2.title = "Title 2";
        todo2.body = "Body 2";
        todo2.done = false;

        todo2.id = TodoDataService::add(todo2);

        todo2.data["key1"] = "value1";
        TodoDataService::add(todo2);

        TodoDataService::setDoneById(todo2.id, true);
    }

    // get TODO items from database
    {
        auto list = TodoDataService::findAllOrderByCreatedAtDesc();

        for (auto &item : list)
        {
            Logger::i("ToDo: " + item.title);
        }
    }

    // login error
    {
        auto data = CustomerSystemService::login("demo-error", "demo-error");
        Logger::i("Customer system service login: " + data.response.message);

        if (data.response.success)
        {
            Logger::i("Customer system service login: OK");
            Logger::i("Customer system service login customer / ID: " + std::to_string(data.customer.id) + " / Name: " + data.customer.name + " / Token: " + data.customer.token + " / Status: " + std::to_string(static_cast<int>(data.customer.status)));
        }
        else
        {
            Logger::e("Customer system service login: FAIL");
            Logger::e("Customer system service login error: " + data.response.error.message);
        }
    }

    // login success
    {
        auto data = CustomerSystemService::login("demo", "demo");
        Logger::i("Customer system service login: " + data.response.message);

        if (data.response.success)
        {
            Logger::i("Customer system service login: OK");
            Logger::i("Customer system service login customer / ID: " + std::to_string(data.customer.id) + " / Name: " + data.customer.name + " / Token: " + data.customer.token + " / Status: " + std::to_string(static_cast<int>(data.customer.status)));
        }
        else
        {
            Logger::e("Customer system service login: FAIL");
            Logger::e("Customer system service login error: " + data.response.error.message);
        }
    }

    // show logged user
    {
        auto customer = ApplicationCore::shared()->getCustomer();
        Logger::i("Current customer ID: " + std::to_string(customer.id) + " - " + customer.name + " - " + customer.token);
        Logger::i("Current customer token: " + CustomerHelper::getToken());
        Logger::i("Current customer is logged: " + std::string((CustomerHelper::isLogged() ? "YES" : "NO")));
    }

    // post http request
    auto httpRequest = HttpRequest("http://httpbin.org/post", HttpMethod::METHOD_POST, {}, {}, "");
    auto httpResponse = HttpClient::shared()->doRequest(httpRequest);
    Logger::i("Response: " + httpResponse.body);

    // secret key store internal
    auto secret = EnvironmentHelper::getSecretKey();

    Logger::i("Secret: " + secret);
    Logger::i("Current datetime UTC: " + DateTime::getCurrentDateTimeAsString());
    Logger::i("String to upper: " + StringHelper::toUpper(StringHelper::trim(" ezored ")));

    // file helper
    {
        Logger::i("Filename: " + FileHelper::getFilename(FileHelper::join(homeDir, "database.db3")));
        Logger::i("Basename: " + FileHelper::getBasename(FileHelper::join(homeDir, "database.db3")));
        Logger::i("File size: " + std::to_string(FileHelper::getFileSize(FileHelper::join(homeDir, "database.db3"))));
        Logger::i("File extesion: " + FileHelper::getExtension(FileHelper::join(homeDir, "database.db3")));
        Logger::i("Is file (file): " + std::to_string(FileHelper::isFile(FileHelper::join(homeDir, "database.db3"))));
        Logger::i("Is file (dir): " + std::to_string(FileHelper::isFile(homeDir)));
        Logger::i("Is dir (file): " + std::to_string(FileHelper::isDir(FileHelper::join(homeDir, "database.db3"))));
        Logger::i("Is dir (dir): " + std::to_string(FileHelper::isDir(homeDir)));

        Logger::i("URL basename: " + FileHelper::getBasenameFromUrl("https://www.w3.org/WAI/ER/tests/xhtml/testfiles/resources/pdf/dummy.pdf"));
        Logger::i("URL filename: " + FileHelper::getFilenameFromUrl("https://www.w3.org/WAI/ER/tests/xhtml/testfiles/resources/pdf/dummy.pdf"));
    }

    // shared data
    SharedData::shared()->start("app");

    if (SharedData::shared()->getBoolWithDefaultValue("first-open", true))
    {
        Logger::i("First open: YES");
        SharedData::shared()->setBool("first-open", false);
        SharedData::shared()->saveAsync();
    }
    else
    {
        Logger::i("First open: NO");
        SharedData::shared()->finish();
    }

    return EXIT_SUCCESS;
}
