// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from vipuser.djinni

#import "VPDVipUserWrapListener+Private.h"
#import "VPDVipUserWrapListener.h"
#import "DJIMarshal+Private.h"
#import "DJIObjcWrapperCache+Private.h"
#import "VPDReplyResult+Private.h"
#import "VPDTokenInfo+Private.h"
#include <stdexcept>

static_assert(__has_feature(objc_arc), "Djinni requires ARC to be enabled for this file");

namespace djinni_generated {

class VipUserWrapListener::ObjcProxy final
: public ::vipuser_djinni::VipUserWrapListener
, private ::djinni::ObjcProxyBase<ObjcType>
{
    friend class ::djinni_generated::VipUserWrapListener;
public:
    using ObjcProxyBase::ObjcProxyBase;
    void on_create_account(const ::vipuser_djinni::ReplyResult & c_result, const ::vipuser_djinni::TokenInfo & c_token) override
    {
        @autoreleasepool {
            [djinni_private_get_proxied_objc_object() onCreateAccount:(::djinni_generated::ReplyResult::fromCpp(c_result))
                                                                token:(::djinni_generated::TokenInfo::fromCpp(c_token))];
        }
    }
    void on_login(const ::vipuser_djinni::ReplyResult & c_result, const ::vipuser_djinni::TokenInfo & c_token) override
    {
        @autoreleasepool {
            [djinni_private_get_proxied_objc_object() onLogin:(::djinni_generated::ReplyResult::fromCpp(c_result))
                                                        token:(::djinni_generated::TokenInfo::fromCpp(c_token))];
        }
    }
    void on_re_login(const ::vipuser_djinni::ReplyResult & c_result, const ::vipuser_djinni::TokenInfo & c_token) override
    {
        @autoreleasepool {
            [djinni_private_get_proxied_objc_object() onReLogin:(::djinni_generated::ReplyResult::fromCpp(c_result))
                                                          token:(::djinni_generated::TokenInfo::fromCpp(c_token))];
        }
    }
    void on_logout(const ::vipuser_djinni::ReplyResult & c_result) override
    {
        @autoreleasepool {
            [djinni_private_get_proxied_objc_object() onLogout:(::djinni_generated::ReplyResult::fromCpp(c_result))];
        }
    }
    void on_do_business(const ::vipuser_djinni::ReplyResult & c_result, const std::vector<uint8_t> & c_response) override
    {
        @autoreleasepool {
            [djinni_private_get_proxied_objc_object() onDoBusiness:(::djinni_generated::ReplyResult::fromCpp(c_result))
                                                          response:(::djinni::Binary::fromCpp(c_response))];
        }
    }
};

}  // namespace djinni_generated

namespace djinni_generated {

auto VipUserWrapListener::toCpp(ObjcType objc) -> CppType
{
    if (!objc) {
        return nullptr;
    }
    return ::djinni::get_objc_proxy<ObjcProxy>(objc);
}

auto VipUserWrapListener::fromCppOpt(const CppOptType& cpp) -> ObjcType
{
    if (!cpp) {
        return nil;
    }
    return dynamic_cast<ObjcProxy&>(*cpp).djinni_private_get_proxied_objc_object();
}

}  // namespace djinni_generated
