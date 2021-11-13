// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from proj.djinni

#import "ezored/helpers/EZRHelpersSharedDataHelper+Private.h"
#import "ezored/helpers/EZRHelpersSharedDataHelper.h"
#import "DJICppWrapperCache+Private.h"
#import "DJIError.h"
#import "DJIMarshal+Private.h"
#import "ezored/domain/EZRDomainCustomer+Private.h"
#include <exception>
#include <stdexcept>
#include <utility>

static_assert(__has_feature(objc_arc), "Djinni requires ARC to be enabled for this file");

@interface EZRHelpersSharedDataHelper ()

- (id)initWithCpp:(const std::shared_ptr<::ezored::helpers::SharedDataHelper>&)cppRef;

@end

@implementation EZRHelpersSharedDataHelper {
    ::djinni::CppProxyCache::Handle<std::shared_ptr<::ezored::helpers::SharedDataHelper>> _cppRefHandle;
}

- (id)initWithCpp:(const std::shared_ptr<::ezored::helpers::SharedDataHelper>&)cppRef
{
    if (self = [super init]) {
        _cppRefHandle.assign(cppRef);
    }
    return self;
}

+ (void)setCustomer:(nonnull EZRDomainCustomer *)value {
    try {
        ::ezored::helpers::SharedDataHelper::setCustomer(::djinni_generated::Customer::toCpp(value));
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

+ (nonnull EZRDomainCustomer *)getCustomer {
    try {
        auto objcpp_result_ = ::ezored::helpers::SharedDataHelper::getCustomer();
        return ::djinni_generated::Customer::fromCpp(objcpp_result_);
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

+ (void)storeCustomer {
    try {
        ::ezored::helpers::SharedDataHelper::storeCustomer();
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

+ (void)setDemoFlag:(BOOL)value {
    try {
        ::ezored::helpers::SharedDataHelper::setDemoFlag(::djinni::Bool::toCpp(value));
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

+ (BOOL)getDemoFlag {
    try {
        auto objcpp_result_ = ::ezored::helpers::SharedDataHelper::getDemoFlag();
        return ::djinni::Bool::fromCpp(objcpp_result_);
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

namespace djinni_generated {

auto SharedDataHelper::toCpp(ObjcType objc) -> CppType
{
    if (!objc) {
        return nullptr;
    }
    return objc->_cppRefHandle.get();
}

auto SharedDataHelper::fromCppOpt(const CppOptType& cpp) -> ObjcType
{
    if (!cpp) {
        return nil;
    }
    return ::djinni::get_cpp_proxy<EZRHelpersSharedDataHelper>(cpp);
}

}  // namespace djinni_generated

@end
