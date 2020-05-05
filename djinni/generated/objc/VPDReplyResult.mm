// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from vipuser.djinni

#import "VPDReplyResult.h"


@implementation VPDReplyResult

- (nonnull instancetype)initWithCode:(int32_t)code
                             message:(nonnull NSString *)message
{
    if (self = [super init]) {
        _code = code;
        _message = [message copy];
    }
    return self;
}

+ (nonnull instancetype)replyResultWithCode:(int32_t)code
                                    message:(nonnull NSString *)message
{
    return [(VPDReplyResult*)[self alloc] initWithCode:code
                                               message:message];
}

- (NSString *)description
{
    return [NSString stringWithFormat:@"<%@ %p code:%@ message:%@>", self.class, (void *)self, @(self.code), self.message];
}

@end