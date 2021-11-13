// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from proj.djinni

#include "com/ezored/systemservices/EZRSystemServicesCustomerSystemServiceLoginData.hpp"  // my header
#include "com/ezored/domain/EZRDomainCustomer.hpp"
#include "com/ezored/domain/EZRDomainResponse.hpp"

namespace djinni_generated {

EZRSystemServicesCustomerSystemServiceLoginData::EZRSystemServicesCustomerSystemServiceLoginData() = default;

EZRSystemServicesCustomerSystemServiceLoginData::~EZRSystemServicesCustomerSystemServiceLoginData() = default;

auto EZRSystemServicesCustomerSystemServiceLoginData::fromCpp(JNIEnv* jniEnv, const CppType& c) -> ::djinni::LocalRef<JniType> {
    const auto& data = ::djinni::JniClass<EZRSystemServicesCustomerSystemServiceLoginData>::get();
    auto r = ::djinni::LocalRef<JniType>{jniEnv->NewObject(data.clazz.get(), data.jconstructor,
                                                           ::djinni::get(::djinni_generated::EZRDomainResponse::fromCpp(jniEnv, c.response)),
                                                           ::djinni::get(::djinni_generated::EZRDomainCustomer::fromCpp(jniEnv, c.customer)))};
    ::djinni::jniExceptionCheck(jniEnv);
    return r;
}

auto EZRSystemServicesCustomerSystemServiceLoginData::toCpp(JNIEnv* jniEnv, JniType j) -> CppType {
    ::djinni::JniLocalScope jscope(jniEnv, 3);
    assert(j != nullptr);
    const auto& data = ::djinni::JniClass<EZRSystemServicesCustomerSystemServiceLoginData>::get();
    return {::djinni_generated::EZRDomainResponse::toCpp(jniEnv, jniEnv->GetObjectField(j, data.field_mResponse)),
            ::djinni_generated::EZRDomainCustomer::toCpp(jniEnv, jniEnv->GetObjectField(j, data.field_mCustomer))};
}

}  // namespace djinni_generated
