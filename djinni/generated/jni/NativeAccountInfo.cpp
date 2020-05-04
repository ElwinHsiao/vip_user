// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from vipuser.djinni

#include "NativeAccountInfo.hpp"  // my header
#include "Marshal.hpp"

namespace djinni_generated {

NativeAccountInfo::NativeAccountInfo() = default;

NativeAccountInfo::~NativeAccountInfo() = default;

auto NativeAccountInfo::fromCpp(JNIEnv* jniEnv, const CppType& c) -> ::djinni::LocalRef<JniType> {
    const auto& data = ::djinni::JniClass<NativeAccountInfo>::get();
    auto r = ::djinni::LocalRef<JniType>{jniEnv->NewObject(data.clazz.get(), data.jconstructor,
                                                           ::djinni::get(::djinni::String::fromCpp(jniEnv, c.user_name)),
                                                           ::djinni::get(::djinni::String::fromCpp(jniEnv, c.password)))};
    ::djinni::jniExceptionCheck(jniEnv);
    return r;
}

auto NativeAccountInfo::toCpp(JNIEnv* jniEnv, JniType j) -> CppType {
    ::djinni::JniLocalScope jscope(jniEnv, 3);
    assert(j != nullptr);
    const auto& data = ::djinni::JniClass<NativeAccountInfo>::get();
    return {::djinni::String::toCpp(jniEnv, (jstring)jniEnv->GetObjectField(j, data.field_mUserName)),
            ::djinni::String::toCpp(jniEnv, (jstring)jniEnv->GetObjectField(j, data.field_mPassword))};
}

}  // namespace djinni_generated