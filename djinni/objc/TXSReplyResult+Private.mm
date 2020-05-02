// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from vipuser.djinni

#import "TXSReplyResult+Private.h"
#import "DJIMarshal+Private.h"
#include <cassert>

namespace djinni_generated {

auto ReplyResult::toCpp(ObjcType obj) -> CppType
{
    assert(obj);
    return {::djinni::I32::toCpp(obj.code),
            ::djinni::String::toCpp(obj.message)};
}

auto ReplyResult::fromCpp(const CppType& cpp) -> ObjcType
{
    return [[TXSReplyResult alloc] initWithCode:(::djinni::I32::fromCpp(cpp.code))
                                        message:(::djinni::String::fromCpp(cpp.message))];
}

}  // namespace djinni_generated
