// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from vipuser.djinni

#import "VPDAccessTicket.h"
#include "access_ticket.hpp"

static_assert(__has_feature(objc_arc), "Djinni requires ARC to be enabled for this file");

@class VPDAccessTicket;

namespace djinni_generated {

struct AccessTicket
{
    using CppType = ::vipuser_djinni::AccessTicket;
    using ObjcType = VPDAccessTicket*;

    using Boxed = AccessTicket;

    static CppType toCpp(ObjcType objc);
    static ObjcType fromCpp(const CppType& cpp);
};

}  // namespace djinni_generated