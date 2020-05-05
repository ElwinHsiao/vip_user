// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from vipuser.djinni

#include "NativeVipUserClientWrap.hpp"  // my header
#include "Marshal.hpp"
#include "NativeAccessTicket.hpp"
#include "NativeAccountInfo.hpp"
#include "NativeVipUserWrapListener.hpp"

namespace djinni_generated {

NativeVipUserClientWrap::NativeVipUserClientWrap() : ::djinni::JniInterface<::vipuser_djinni::VipUserClientWrap, NativeVipUserClientWrap>("per/elwin/vipuser/djinni/VipUserClientWrap$CppProxy") {}

NativeVipUserClientWrap::~NativeVipUserClientWrap() = default;


CJNIEXPORT void JNICALL Java_per_elwin_vipuser_djinni_VipUserClientWrap_00024CppProxy_nativeDestroy(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        delete reinterpret_cast<::djinni::CppProxyHandle<::vipuser_djinni::VipUserClientWrap>*>(nativeRef);
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, )
}

CJNIEXPORT void JNICALL Java_per_elwin_vipuser_djinni_VipUserClientWrap_00024CppProxy_native_1createAccount(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef, jobject j_account)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::vipuser_djinni::VipUserClientWrap>(nativeRef);
        ref->create_account(::djinni_generated::NativeAccountInfo::toCpp(jniEnv, j_account));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, )
}

CJNIEXPORT void JNICALL Java_per_elwin_vipuser_djinni_VipUserClientWrap_00024CppProxy_native_1login(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef, jobject j_account)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::vipuser_djinni::VipUserClientWrap>(nativeRef);
        ref->login(::djinni_generated::NativeAccountInfo::toCpp(jniEnv, j_account));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, )
}

CJNIEXPORT void JNICALL Java_per_elwin_vipuser_djinni_VipUserClientWrap_00024CppProxy_native_1reLogin(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef, jobject j_ticket)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::vipuser_djinni::VipUserClientWrap>(nativeRef);
        ref->re_login(::djinni_generated::NativeAccessTicket::toCpp(jniEnv, j_ticket));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, )
}

CJNIEXPORT void JNICALL Java_per_elwin_vipuser_djinni_VipUserClientWrap_00024CppProxy_native_1logout(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef, jobject j_ticket)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::vipuser_djinni::VipUserClientWrap>(nativeRef);
        ref->logout(::djinni_generated::NativeAccessTicket::toCpp(jniEnv, j_ticket));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, )
}

CJNIEXPORT void JNICALL Java_per_elwin_vipuser_djinni_VipUserClientWrap_00024CppProxy_native_1doBusiness(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef, jobject j_ticket, jbyteArray j_request)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::vipuser_djinni::VipUserClientWrap>(nativeRef);
        ref->do_business(::djinni_generated::NativeAccessTicket::toCpp(jniEnv, j_ticket),
                         ::djinni::Binary::toCpp(jniEnv, j_request));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, )
}

CJNIEXPORT jobject JNICALL Java_per_elwin_vipuser_djinni_VipUserClientWrap_00024CppProxy_createWithListener(JNIEnv* jniEnv, jobject /*this*/, jobject j_listener)
{
    try {
        DJINNI_FUNCTION_PROLOGUE0(jniEnv);
        auto r = ::vipuser_djinni::VipUserClientWrap::create_with_listener(::djinni_generated::NativeVipUserWrapListener::toCpp(jniEnv, j_listener));
        return ::djinni::release(::djinni_generated::NativeVipUserClientWrap::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

}  // namespace djinni_generated
