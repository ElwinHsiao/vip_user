// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from vipuser.djinni

#pragma once

#include <cstdint>
#include <string>
#include <utility>

namespace vipuser_djinni {

struct TokenInfo final {
    std::string uuid;
    std::string access_token;
    std::string refresh_token;
    int64_t access_token_expire;
    int64_t refresh_token_expire;

    TokenInfo(std::string uuid_,
              std::string access_token_,
              std::string refresh_token_,
              int64_t access_token_expire_,
              int64_t refresh_token_expire_)
    : uuid(std::move(uuid_))
    , access_token(std::move(access_token_))
    , refresh_token(std::move(refresh_token_))
    , access_token_expire(std::move(access_token_expire_))
    , refresh_token_expire(std::move(refresh_token_expire_))
    {}
};

}  // namespace vipuser_djinni
