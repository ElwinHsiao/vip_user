// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from vipuser.djinni

#pragma once

#include "djinni_support.hpp"
#include "vip_user_client_wrap.hpp"

namespace djinni_generated {

class NativeVipUserClientWrap final : ::djinni::JniInterface<::vipuser_djinni::VipUserClientWrap, NativeVipUserClientWrap> {
public:
    using CppType = std::shared_ptr<::vipuser_djinni::VipUserClientWrap>;
    using CppOptType = std::shared_ptr<::vipuser_djinni::VipUserClientWrap>;
    using JniType = jobject;

    using Boxed = NativeVipUserClientWrap;

    ~NativeVipUserClientWrap();

    static CppType toCpp(JNIEnv* jniEnv, JniType j) { return ::djinni::JniClass<NativeVipUserClientWrap>::get()._fromJava(jniEnv, j); }
    static ::djinni::LocalRef<JniType> fromCppOpt(JNIEnv* jniEnv, const CppOptType& c) { return {jniEnv, ::djinni::JniClass<NativeVipUserClientWrap>::get()._toJava(jniEnv, c)}; }
    static ::djinni::LocalRef<JniType> fromCpp(JNIEnv* jniEnv, const CppType& c) { return fromCppOpt(jniEnv, c); }

private:
    NativeVipUserClientWrap();
    friend ::djinni::JniClass<NativeVipUserClientWrap>;
    friend ::djinni::JniInterface<::vipuser_djinni::VipUserClientWrap, NativeVipUserClientWrap>;

};

}  // namespace djinni_generated
