// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from vipuser.djinni

#import "VPUReplyResult.h"
#import "VPUTokenInfo.h"
#import <Foundation/Foundation.h>


@protocol VPUVipUserWrapListener

- (void)onCreateAccount:(nonnull VPUReplyResult *)result
                  token:(nonnull VPUTokenInfo *)token;

- (void)onLogin:(nonnull VPUReplyResult *)result
          token:(nonnull VPUTokenInfo *)token;

- (void)onReLogin:(nonnull VPUReplyResult *)result
            token:(nonnull VPUTokenInfo *)token;

- (void)onLogout:(nonnull VPUReplyResult *)result;

- (void)onDoBusiness:(nonnull VPUReplyResult *)result
            response:(nonnull NSData *)response;

@end