// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from proj.djinni

#include "com/ezored/domain/EZRDomainTodo.hpp"  // my header
#include "Marshal.hpp"

namespace djinni_generated {

EZRDomainTodo::EZRDomainTodo() = default;

EZRDomainTodo::~EZRDomainTodo() = default;

auto EZRDomainTodo::fromCpp(JNIEnv* jniEnv, const CppType& c) -> ::djinni::LocalRef<JniType> {
    const auto& data = ::djinni::JniClass<EZRDomainTodo>::get();
    auto r = ::djinni::LocalRef<JniType>{jniEnv->NewObject(data.clazz.get(), data.jconstructor,
                                                           ::djinni::get(::djinni::I64::fromCpp(jniEnv, c.id)),
                                                           ::djinni::get(::djinni::String::fromCpp(jniEnv, c.title)),
                                                           ::djinni::get(::djinni::String::fromCpp(jniEnv, c.body)),
                                                           ::djinni::get(::djinni::Map<::djinni::String, ::djinni::String>::fromCpp(jniEnv, c.data)),
                                                           ::djinni::get(::djinni::Bool::fromCpp(jniEnv, c.done)),
                                                           ::djinni::get(::djinni::Date::fromCpp(jniEnv, c.createdAt)),
                                                           ::djinni::get(::djinni::Date::fromCpp(jniEnv, c.updatedAt)))};
    ::djinni::jniExceptionCheck(jniEnv);
    return r;
}

auto EZRDomainTodo::toCpp(JNIEnv* jniEnv, JniType j) -> CppType {
    ::djinni::JniLocalScope jscope(jniEnv, 8);
    assert(j != nullptr);
    const auto& data = ::djinni::JniClass<EZRDomainTodo>::get();
    return {::djinni::I64::toCpp(jniEnv, jniEnv->GetLongField(j, data.field_mId)),
            ::djinni::String::toCpp(jniEnv, (jstring)jniEnv->GetObjectField(j, data.field_mTitle)),
            ::djinni::String::toCpp(jniEnv, (jstring)jniEnv->GetObjectField(j, data.field_mBody)),
            ::djinni::Map<::djinni::String, ::djinni::String>::toCpp(jniEnv, jniEnv->GetObjectField(j, data.field_mData)),
            ::djinni::Bool::toCpp(jniEnv, jniEnv->GetBooleanField(j, data.field_mDone)),
            ::djinni::Date::toCpp(jniEnv, jniEnv->GetObjectField(j, data.field_mCreatedAt)),
            ::djinni::Date::toCpp(jniEnv, jniEnv->GetObjectField(j, data.field_mUpdatedAt))};
}

}  // namespace djinni_generated
