#ifndef _ACCOUNT_SERVER_H_
#define _ACCOUNT_SERVER_H_

#include <iostream>
#include "psql_helper.h"

namespace vipuser {

    

class AccountService {
public:
    AccountService();
    ~AccountService();
    // VipUserStatus CreateAccount(std::string userAlias, std::string passwordSHA256, UserTicket &ticket);
    // VipUserStatus Login(std::string userAlias, std::string passwordSHA256, UserTicket &ticket);
    // VipUserStatus CheckLogin(std::string accessToken);
    // VipUserStatus Logout(std::string accessToken);
    // VipUserStatus Relogin(std::string refreshToken, UserTicket &ticket);
    VipUserStatus AddUser(std::string userAlias, std::string passwordSHA256, std::string& outUuid);
    VipUserStatus CheckUser(std::string userAlias, std::string passwordSHA256, std::string& outUuid);
private:
    Psql *_psql;

    // VipUserStatus StoreNewUser(std::string uuid, std::string userId, std::string passwordSHA256);
    int CheckUserAliasExist(std::string userAlias);
};


};

#endif