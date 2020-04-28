#ifndef _VIPUSER_SERVER_H_
#define _VIPUSER_SERVER_H_

#include <iostream>
#include "redis_helper.h"
#include "crypt_plus.h"

namespace vipuser {

    
enum VipUserStatus {
    VipUserStatusOK = 0,
    VipUserStatusError = -1,
    VipUserStatusErrorFormat = -3,
    VipUserStatusAccountExist = -10001,
    VipUserStatusAccountNotExist = -10002,
};
struct VipUserTicket {
    std::string accessToken;
    std::string refreshToken;
};
class AccountServer {
public:
    AccountServer(Redis &redis);
    ~AccountServer();
    VipUserStatus CreateAccount(std::string userId, std::string passwordSHA256, VipUserTicket &ticket);
    VipUserStatus Login(std::string userId, std::string passwordSHA256, VipUserTicket &ticket);
    VipUserStatus CheckLogin(std::string accessToken);
    VipUserStatus Logout(std::string accessToken);
    VipUserStatus Relogin(std::string refreshToken, VipUserTicket &ticket);
private:
    Redis &_redis;
    CryptPlus *_cryptPlus;

    std::string Genuuid();
    VipUserStatus StoreNewUser(std::string uuid, std::string userId, std::string passwordSHA256);
    std::string MakeRefreshToken(std::string uuid, uint64_t timestamp, std::string key);
    bool AccountExist(std::string userId);
};


};

#endif