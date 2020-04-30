#ifndef _ACCOUNT_SERVER_H_
#define _ACCOUNT_SERVER_H_

#include <iostream>
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
class AccountService {
public:
    AccountService(Psql &_psql);
    ~AccountService();
    VipUserStatus CreateAccount(std::string userAlias, std::string passwordSHA256, UserTicket &ticket);
    VipUserStatus Login(std::string userAlias, std::string passwordSHA256, UserTicket &ticket);
    VipUserStatus CheckLogin(std::string accessToken);
    VipUserStatus Logout(std::string accessToken);
    VipUserStatus Relogin(std::string refreshToken, UserTicket &ticket);
private:
    Psql &_psql;

    VipUserStatus StoreNewUser(std::string uuid, std::string userId, std::string passwordSHA256);
    int CheckUserAliasExist(std::string userAlias);
};


};

#endif