#ifndef _VIPUSER_COMMON_H_
#define _VIPUSER_COMMON_H_

#include <iostream>

// namespace vipuser {

enum VipUserStatus {
    VipUserStatusOK = 0,
    VipUserStatusError = -1,
    VipUserStatusErrorParam = -2,
    VipUserStatusErrorFormat = -3,
    VipUserStatusDBFailed = -4,
    VipUserStatusRedisError = -5,

    VipUserStatusAccountExist = -10001,
    VipUserStatusAccountNotExist = -10002,
    VipUserStatusErrorPassword = -10001,

    VipUserStatusTicketError = -20001,
};

struct AccountDetailInfo {
    std::string uuid;
    std::string userAlias;
    std::string passwordSum;
    std::string email;
    std::string phone;
    uint64_t createTimeMills;
    uint64_t index;     // the DB auto increate index;
};


struct TokenInfo {
    std::string accessToken;
    std::string refreshToken;
    uint64_t accessTokenExpiredInSecs;
    uint64_t refreshTokenExpiredInSecs;
};

struct UserTicket {
    std::string uuid;
    TokenInfo tokenInfo;
};


uint64_t getCurrentTimeMills();
uint64_t genRandom();
std::string generateUuid();

std::string toHex(void *const data, const size_t dataLength);
size_t fromHex(const std::string &in, void *const data);

// }


#endif
