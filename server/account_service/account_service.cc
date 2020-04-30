#include "account_service.h"
#include "vipuser_common.h"

using namespace vipuser;



VipUserStatus readUserDetail(std::string uuid, AccountDetailInfo &accountDetail) {

    return VipUserStatusOK;
}



AccountService::AccountService(Psql &psql): _psql(psql) 
{
    
}

AccountService::~AccountService() 
{
    
}

VipUserStatus AccountService::CreateAccount(std::string userAlias, std::string passwordSHA256, UserTicket &ticket)
{
    int exist = CheckUserAliasExist(userAlias);
    if (exist < 0) {
        return VipUserStatusError;
    } 
    if (exist == 1) {
        return VipUserStatusAccountExist;
    }
    std::string uuid = generateUuid();
    auto status = StoreNewUser(uuid, userAlias, passwordSHA256);
    if (status != VipUserStatusOK) {
        return status;
    }

    // std::string refreshToken = MakeRefreshToken(uuid, getCurrentTimeMills(), passwordSHA256);
    // if (refreshToken.size() == 0) {
    //     return VipUserStatusError;
    // }
    // ticket.refreshToken = refreshToken;
    // ticket.accessToken = sha256(refreshToken);

    return VipUserStatusOK;
}

VipUserStatus AccountService::Login(std::string userAlias, std::string passwordSHA256, UserTicket &ticket)
{
    int exist = CheckUserAliasExist(userAlias);
    if (exist < 0) {
        return VipUserStatusError;
    } 
    if (exist == 0) {
        return VipUserStatusAccountExist;
    }

    // validate password
    // ...


    return VipUserStatusOK;
}

VipUserStatus AccountService::CheckLogin(std::string accessToken)
{
    
    return VipUserStatusOK;
}

VipUserStatus AccountService::Logout(std::string accessToken)
{
    return VipUserStatusOK;
}

VipUserStatus AccountService::Relogin(std::string refreshToken, UserTicket &ticket)
{
    return VipUserStatusOK;
}

int AccountService::CheckUserAliasExist(std::string userAlias) {

    // check db contains
    // ...

    return false;
}


VipUserStatus AccountService::StoreNewUser(std::string uuid, std::string userId, std::string passwordSHA256)
{
    // store to db
    // ...
    return VipUserStatusOK;
}



// VipUserStatus WriteSession(std::string accessToken, std::string refreshToken) {
    
// }
