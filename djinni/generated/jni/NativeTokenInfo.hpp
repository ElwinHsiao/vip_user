// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from vipuser.djinni

#pragma once

#include "djinni_support.hpp"
#include "token_info.hpp"

namespace djinni_generated {

class NativeTokenInfo final {
public:
    using CppType = ::vipuser_djinni::TokenInfo;
    using JniType = jobject;

    using Boxed = NativeTokenInfo;

    ~NativeTokenInfo();

    static CppType toCpp(JNIEnv* jniEnv, JniType j);
    static ::djinni::LocalRef<JniType> fromCpp(JNIEnv* jniEnv, const CppType& c);

private:
    NativeTokenInfo();
    friend ::djinni::JniClass<NativeTokenInfo>;

    const ::djinni::GlobalRef<jclass> clazz { ::djinni::jniFindClass("per/elwin/vipuser/djinni/TokenInfo") };
    const jmethodID jconstructor { ::djinni::jniGetMethodID(clazz.get(), "<init>", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;JJ)V") };
    const jfieldID field_mUuid { ::djinni::jniGetFieldID(clazz.get(), "mUuid", "Ljava/lang/String;") };
    const jfieldID field_mAccessToken { ::djinni::jniGetFieldID(clazz.get(), "mAccessToken", "Ljava/lang/String;") };
    const jfieldID field_mRefreshToken { ::djinni::jniGetFieldID(clazz.get(), "mRefreshToken", "Ljava/lang/String;") };
    const jfieldID field_mAccessTokenExpire { ::djinni::jniGetFieldID(clazz.get(), "mAccessTokenExpire", "J") };
    const jfieldID field_mRefreshTokenExpire { ::djinni::jniGetFieldID(clazz.get(), "mRefreshTokenExpire", "J") };
};

}  // namespace djinni_generated
