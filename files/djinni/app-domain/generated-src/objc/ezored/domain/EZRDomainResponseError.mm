// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from proj.djinni

#import "ezored/domain/EZRDomainResponseError.h"


@implementation EZRDomainResponseError

- (nonnull instancetype)initWithField:(nonnull NSString *)field
                              message:(nonnull NSString *)message
{
    if (self = [super init]) {
        _field = [field copy];
        _message = [message copy];
    }
    return self;
}

+ (nonnull instancetype)responseErrorWithField:(nonnull NSString *)field
                                       message:(nonnull NSString *)message
{
    return [(EZRDomainResponseError*)[self alloc] initWithField:field
                                                        message:message];
}

- (NSString *)description
{
    return [NSString stringWithFormat:@"<%@ %p field:%@ message:%@>", self.class, (void *)self, self.field, self.message];
}

@end
