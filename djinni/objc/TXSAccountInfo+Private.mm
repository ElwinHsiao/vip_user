// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from vipuser.djinni

#import "TXSAccountInfo+Private.h"
#import "DJIMarshal+Private.h"
#include <cassert>

namespace djinni_generated {

auto AccountInfo::toCpp(ObjcType obj) -> CppType
{
    assert(obj);
    return {::djinni::String::toCpp(obj.userName),
            ::djinni::String::toCpp(obj.password)};
}

auto AccountInfo::fromCpp(const CppType& cpp) -> ObjcType
{
    return [[TXSAccountInfo alloc] initWithUserName:(::djinni::String::fromCpp(cpp.user_name))
                                           password:(::djinni::String::fromCpp(cpp.password))];
}

}  // namespace djinni_generated
