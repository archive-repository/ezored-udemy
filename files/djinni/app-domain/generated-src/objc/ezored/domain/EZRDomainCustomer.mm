// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from proj.djinni

#import "ezored/domain/EZRDomainCustomer.h"


@implementation EZRDomainCustomer

- (nonnull instancetype)initWithId:(int64_t)id
                              name:(nonnull NSString *)name
                             token:(nonnull NSString *)token
                            status:(EZREnumsCustomerStatusEnum)status
{
    if (self = [super init]) {
        _id = id;
        _name = [name copy];
        _token = [token copy];
        _status = status;
    }
    return self;
}

+ (nonnull instancetype)customerWithId:(int64_t)id
                                  name:(nonnull NSString *)name
                                 token:(nonnull NSString *)token
                                status:(EZREnumsCustomerStatusEnum)status
{
    return [(EZRDomainCustomer*)[self alloc] initWithId:id
                                                   name:name
                                                  token:token
                                                 status:status];
}

- (NSString *)description
{
    return [NSString stringWithFormat:@"<%@ %p id:%@ name:%@ token:%@ status:%@>", self.class, (void *)self, @(self.id), self.name, self.token, @(self.status)];
}

@end
