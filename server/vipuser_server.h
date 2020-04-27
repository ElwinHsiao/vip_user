#ifndef _VIPUSER_SERVER_H_
#define _VIPUSER_SERVER_H_

#include <iostream>
#include "dbhelper.h"

namespace vipuser {
    
    enum VipUserStatus {
        VipUserStatusOK = 0,
        VipUserStatusError = -1,
    };

    struct VipUserTicket {
        std::string accessToken;
        std::string refreshToken;
    };

    class AccountServer {
    public:
        AccountServer(Redis &redis);
        ~AccountServer();
        VipUserStatus createAccount(std::string userId, std::string passwordHash, VipUserTicket &ticket);
        VipUserStatus Login(std::string userId, std::string passwordHash, VipUserTicket &ticket);
        VipUserStatus Logout(std::string accessToken);
        VipUserStatus Relogin(std::string refreshToken, VipUserTicket &ticket);

    private:
        Redis &_redis;

        std::string Genuuid();

    };

};

#endif