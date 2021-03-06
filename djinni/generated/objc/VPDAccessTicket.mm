// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from vipuser.djinni

#import "VPDAccessTicket.h"


@implementation VPDAccessTicket

- (nonnull instancetype)initWithUuid:(nonnull NSString *)uuid
                         accessToken:(nonnull NSString *)accessToken
{
    if (self = [super init]) {
        _uuid = [uuid copy];
        _accessToken = [accessToken copy];
    }
    return self;
}

+ (nonnull instancetype)accessTicketWithUuid:(nonnull NSString *)uuid
                                 accessToken:(nonnull NSString *)accessToken
{
    return [(VPDAccessTicket*)[self alloc] initWithUuid:uuid
                                            accessToken:accessToken];
}

- (NSString *)description
{
    return [NSString stringWithFormat:@"<%@ %p uuid:%@ accessToken:%@>", self.class, (void *)self, self.uuid, self.accessToken];
}

@end
