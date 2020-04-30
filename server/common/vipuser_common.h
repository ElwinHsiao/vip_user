#ifndef _VIPUSER_COMMON_H_
#define _VIPUSER_COMMON_H_

#include <iostream>

// namespace vipuser {

struct AccountDetailInfo {
    std::string uuid;
    std::string userAlias;
    std::string passwordSum;
    std::string email;
    std::string phone;
    uint64_t createTimeMills;
    uint64_t index;     // the DB auto increate index;
};

struct RefreshTokenInfo
{
    std::string uuid;
    uint64_t timestamp;
    uint64_t salt;
};


uint64_t getCurrentTimeMills();
uint64_t genRandom();
std::string generateUuid();

std::string toHex(void *const data, const size_t dataLength);
size_t fromHex(const std::string &in, void *const data);

// }


#endif
