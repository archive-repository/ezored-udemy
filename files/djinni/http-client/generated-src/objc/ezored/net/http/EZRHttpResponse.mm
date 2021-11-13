// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from proj.djinni

#import "ezored/net/http/EZRHttpResponse.h"


@implementation EZRHttpResponse

- (nonnull instancetype)initWithCode:(int32_t)code
                                body:(nonnull NSString *)body
                                 url:(nonnull NSString *)url
                             headers:(nonnull NSArray<EZRHttpHeader *> *)headers
{
    if (self = [super init]) {
        _code = code;
        _body = [body copy];
        _url = [url copy];
        _headers = [headers copy];
    }
    return self;
}

+ (nonnull instancetype)httpResponseWithCode:(int32_t)code
                                        body:(nonnull NSString *)body
                                         url:(nonnull NSString *)url
                                     headers:(nonnull NSArray<EZRHttpHeader *> *)headers
{
    return [(EZRHttpResponse*)[self alloc] initWithCode:code
                                                   body:body
                                                    url:url
                                                headers:headers];
}

- (NSString *)description
{
    return [NSString stringWithFormat:@"<%@ %p code:%@ body:%@ url:%@ headers:%@>", self.class, (void *)self, @(self.code), self.body, self.url, self.headers];
}

@end
