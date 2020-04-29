#ifndef _ACCOUNT_SERVER_H_
#define _ACCOUNT_SERVER_H_

#include <iostream>
#include "redis_helper.h"
#include "crypt_plus.h"
#include "psql_helper.h"

namespace vipuser {

    
enum VipUserStatus {
    VipUserStatusOK = 0,
    VipUserStatusError = -1,
    VipUserStatusErrorFormat = -3,
    VipUserStatusAccountExist = -10001,
    VipUserStatusAccountNotExist = -10002,
};
struct UserTicket {
    std::string accessToken;
    std::string refreshToken;
};
class AccountServer {
public:
    AccountServer(Redis &redis, Psql &_psql);
    ~AccountServer();
    VipUserStatus CreateAccount(std::string userId, std::string passwordSHA256, UserTicket &ticket);
    VipUserStatus Login(std::string userId, std::string passwordSHA256, UserTicket &ticket);
    VipUserStatus CheckLogin(std::string accessToken);
    VipUserStatus Logout(std::string accessToken);
    VipUserStatus Relogin(std::string refreshToken, UserTicket &ticket);
private:
    Redis &_redis;
    CryptPlus *_cryptPlus;
    Psql &_psql;

    VipUserStatus StoreNewUser(std::string uuid, std::string userId, std::string passwordSHA256);
    std::string MakeRefreshToken(std::string uuid, uint64_t timestamp, std::string key);
    bool AccountExist(std::string userId);
};


};

#endif