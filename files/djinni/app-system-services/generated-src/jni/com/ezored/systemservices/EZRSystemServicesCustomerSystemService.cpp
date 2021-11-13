// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from proj.djinni

#include "com/ezored/systemservices/EZRSystemServicesCustomerSystemService.hpp"  // my header
#include "Marshal.hpp"
#include "com/ezored/systemservices/EZRSystemServicesCustomerSystemServiceLoginData.hpp"

namespace djinni_generated {

EZRSystemServicesCustomerSystemService::EZRSystemServicesCustomerSystemService() : ::djinni::JniInterface<::ezored::systemservices::CustomerSystemService, EZRSystemServicesCustomerSystemService>("com/ezored/systemservices/CustomerSystemService$CppProxy") {}

EZRSystemServicesCustomerSystemService::~EZRSystemServicesCustomerSystemService() = default;


CJNIEXPORT void JNICALL Java_com_ezored_systemservices_CustomerSystemService_00024CppProxy_nativeDestroy(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        delete reinterpret_cast<::djinni::CppProxyHandle<::ezored::systemservices::CustomerSystemService>*>(nativeRef);
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, )
}

CJNIEXPORT jobject JNICALL Java_com_ezored_systemservices_CustomerSystemService_00024CppProxy_login(JNIEnv* jniEnv, jobject /*this*/, jstring j_username, jstring j_password)
{
    try {
        DJINNI_FUNCTION_PROLOGUE0(jniEnv);
        auto r = ::ezored::systemservices::CustomerSystemService::login(::djinni::String::toCpp(jniEnv, j_username),
                                                                        ::djinni::String::toCpp(jniEnv, j_password));
        return ::djinni::release(::djinni_generated::EZRSystemServicesCustomerSystemServiceLoginData::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

}  // namespace djinni_generated
