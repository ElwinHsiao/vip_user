#ifndef _VIPUSER_SERVER_H_
#define _VIPUSER_SERVER_H_

#include <iostream>
#include "access_service.h"
#include "account_service.h"

namespace vipuser {

class VipUserServer
{

public:
    VipUserServer();
    ~VipUserServer();

    VipUserStatus CreateAccount(std::string userAlias, std::string passwordSHA256, UserTicket &ticket);
    VipUserStatus Login(std::string userAlias, std::string passwordSHA256, UserTicket &ticket);
    VipUserStatus CheckLogin(std::string uuid, std::string accessToken);
    VipUserStatus Logout(std::string accessToken);
    VipUserStatus Relogin(std::string refreshToken, UserTicket &ticket);

private:
    AccessService *_accessService;
    AccountService *_accountService;
    

    
};

}

#endif