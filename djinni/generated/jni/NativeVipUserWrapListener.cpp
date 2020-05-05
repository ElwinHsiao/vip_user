// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from vipuser.djinni

#include "NativeVipUserWrapListener.hpp"  // my header
#include "Marshal.hpp"
#include "NativeReplyResult.hpp"
#include "NativeTokenInfo.hpp"

namespace djinni_generated {

NativeVipUserWrapListener::NativeVipUserWrapListener() : ::djinni::JniInterface<::vipuser_djinni::VipUserWrapListener, NativeVipUserWrapListener>() {}

NativeVipUserWrapListener::~NativeVipUserWrapListener() = default;

NativeVipUserWrapListener::JavaProxy::JavaProxy(JniType j) : Handle(::djinni::jniGetThreadEnv(), j) { }

NativeVipUserWrapListener::JavaProxy::~JavaProxy() = default;

void NativeVipUserWrapListener::JavaProxy::on_create_account(const ::vipuser_djinni::ReplyResult & c_result, const ::vipuser_djinni::TokenInfo & c_token) {
    auto jniEnv = ::djinni::jniGetThreadEnv();
    ::djinni::JniLocalScope jscope(jniEnv, 10);
    const auto& data = ::djinni::JniClass<::djinni_generated::NativeVipUserWrapListener>::get();
    jniEnv->CallVoidMethod(Handle::get().get(), data.method_onCreateAccount,
                           ::djinni::get(::djinni_generated::NativeReplyResult::fromCpp(jniEnv, c_result)),
                           ::djinni::get(::djinni_generated::NativeTokenInfo::fromCpp(jniEnv, c_token)));
    ::djinni::jniExceptionCheck(jniEnv);
}
void NativeVipUserWrapListener::JavaProxy::on_login(const ::vipuser_djinni::ReplyResult & c_result, const ::vipuser_djinni::TokenInfo & c_token) {
    auto jniEnv = ::djinni::jniGetThreadEnv();
    ::djinni::JniLocalScope jscope(jniEnv, 10);
    const auto& data = ::djinni::JniClass<::djinni_generated::NativeVipUserWrapListener>::get();
    jniEnv->CallVoidMethod(Handle::get().get(), data.method_onLogin,
                           ::djinni::get(::djinni_generated::NativeReplyResult::fromCpp(jniEnv, c_result)),
                           ::djinni::get(::djinni_generated::NativeTokenInfo::fromCpp(jniEnv, c_token)));
    ::djinni::jniExceptionCheck(jniEnv);
}
void NativeVipUserWrapListener::JavaProxy::on_re_login(const ::vipuser_djinni::ReplyResult & c_result, const ::vipuser_djinni::TokenInfo & c_token) {
    auto jniEnv = ::djinni::jniGetThreadEnv();
    ::djinni::JniLocalScope jscope(jniEnv, 10);
    const auto& data = ::djinni::JniClass<::djinni_generated::NativeVipUserWrapListener>::get();
    jniEnv->CallVoidMethod(Handle::get().get(), data.method_onReLogin,
                           ::djinni::get(::djinni_generated::NativeReplyResult::fromCpp(jniEnv, c_result)),
                           ::djinni::get(::djinni_generated::NativeTokenInfo::fromCpp(jniEnv, c_token)));
    ::djinni::jniExceptionCheck(jniEnv);
}
void NativeVipUserWrapListener::JavaProxy::on_logout(const ::vipuser_djinni::ReplyResult & c_result) {
    auto jniEnv = ::djinni::jniGetThreadEnv();
    ::djinni::JniLocalScope jscope(jniEnv, 10);
    const auto& data = ::djinni::JniClass<::djinni_generated::NativeVipUserWrapListener>::get();
    jniEnv->CallVoidMethod(Handle::get().get(), data.method_onLogout,
                           ::djinni::get(::djinni_generated::NativeReplyResult::fromCpp(jniEnv, c_result)));
    ::djinni::jniExceptionCheck(jniEnv);
}
void NativeVipUserWrapListener::JavaProxy::on_do_business(const ::vipuser_djinni::ReplyResult & c_result, const std::vector<uint8_t> & c_response) {
    auto jniEnv = ::djinni::jniGetThreadEnv();
    ::djinni::JniLocalScope jscope(jniEnv, 10);
    const auto& data = ::djinni::JniClass<::djinni_generated::NativeVipUserWrapListener>::get();
    jniEnv->CallVoidMethod(Handle::get().get(), data.method_onDoBusiness,
                           ::djinni::get(::djinni_generated::NativeReplyResult::fromCpp(jniEnv, c_result)),
                           ::djinni::get(::djinni::Binary::fromCpp(jniEnv, c_response)));
    ::djinni::jniExceptionCheck(jniEnv);
}

}  // namespace djinni_generated
