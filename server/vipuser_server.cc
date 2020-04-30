#include "vipuser_server.h"

using namespace vipuser;


const uint PASSWORD_SUM_LENGTH = 256;

VipUserServer::VipUserServer()
{
    
}

VipUserServer::~VipUserServer()
{
    
}


VipUserStatus VipUserServer::CreateAccount(std::string userAlias, std::string passwordSHA256, UserTicket &ticket)
{
    // if (passwordSHA256.size() != PASSWORD_SUM_LENGTH) {
    //     return VipUserStatusErrorFormat;
    // }

    // std::string uuid = generateUuid();
    // auto status = StoreNewUser(uuid, userId, passwordSHA256);
    // if (status != VipUserStatusOK) {
    //     return status;
    // }

    // std::string refreshToken = MakeRefreshToken(uuid, getCurrentTimeMills(), passwordSHA256);
    // if (refreshToken.size() == 0) {
    //     return VipUserStatusError;
    // }
    // ticket.refreshToken = refreshToken;
    // ticket.accessToken = sha256(refreshToken);

    return VipUserStatusOK;
}

VipUserStatus VipUserServer::Login(std::string userAlias, std::string passwordSHA256, UserTicket &ticket)
{
    // if (!AccountExist(userId)) {
    //     return VipUserStatusAccountNotExist;
    // }

    // validate password
    // ...


    return VipUserStatusOK;
}

VipUserStatus VipUserServer::CheckLogin(std::string accessToken)
{
    
    return VipUserStatusOK;
}

VipUserStatus VipUserServer::Logout(std::string accessToken)
{
    return VipUserStatusOK;
}

VipUserStatus VipUserServer::Relogin(std::string refreshToken, UserTicket &ticket)
{
    return VipUserStatusOK;
}

