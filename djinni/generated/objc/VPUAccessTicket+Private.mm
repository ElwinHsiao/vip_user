// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from vipuser.djinni

#import "VPUAccessTicket+Private.h"
#import "DJIMarshal+Private.h"
#include <cassert>

namespace djinni_generated {

auto AccessTicket::toCpp(ObjcType obj) -> CppType
{
    assert(obj);
    return {::djinni::String::toCpp(obj.uuid),
            ::djinni::String::toCpp(obj.accessToken)};
}

auto AccessTicket::fromCpp(const CppType& cpp) -> ObjcType
{
    return [[VPUAccessTicket alloc] initWithUuid:(::djinni::String::fromCpp(cpp.uuid))
                                     accessToken:(::djinni::String::fromCpp(cpp.access_token))];
}

}  // namespace djinni_generated