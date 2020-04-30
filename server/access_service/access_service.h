#ifndef _ACCESS_SERVICE_H_
#define _ACCESS_SERVICE_H_

#include <iostream>
#include "vipuser_common.h"
#include "redis_helper.h"
#include "crypt_plus.h"


namespace vipuser {


class AccessService {
public:
    AccessService();
    ~AccessService();
    //int isLogined(std::string userAlias);
    VipUserStatus CreateUserTicket(std::string uuid, std::string key, TokenInfo& ticket);
    VipUserStatus DeleteUserTicket(std::string uuid);

private:
    Redis *_redis;
    CryptPlus *_cryptPlus;

    std::string MakeRefreshToken(std::string uuid, std::string key);

};


}
#endif