#include "vipuser_server.h"

using namespace vipuser;


const uint PASSWORD_SUM_LENGTH = 64;

VipUserServer::VipUserServer()
{
    _accountService = new AccountService();
    _accessService = new AccessService();
}

VipUserServer::~VipUserServer()
{
    delete _accountService;
    delete _accessService;
}


VipUserStatus VipUserServer::CreateAccount(std::string userAlias, std::string passwordSHA256, UserTicket &ticket)
{
    if (passwordSHA256.size() != PASSWORD_SUM_LENGTH) {
        return VipUserStatusErrorFormat;
    }

    std::string uuid;
    auto status = _accountService->AddUser(userAlias, passwordSHA256, uuid);
    if (status != VipUserStatusOK) {
        std::cout << "addUser failed: status" << status << std::endl;
        return status;
    }

    std::cout << "add user to DB success, uuid=" << uuid << std::endl;

    TokenInfo tokenInfo;
    status = _accessService->CreateUserTicket(uuid, passwordSHA256, tokenInfo);
        if (status != VipUserStatusOK) {
        std::cout << "create user ticket failed: status" << status << std::endl;
        return status;
    }

    ticket.uuid = uuid;
    ticket.tokenInfo = tokenInfo;

    return VipUserStatusOK;
}

VipUserStatus VipUserServer::Login(std::string userAlias, std::string passwordSHA256, UserTicket &ticket)
{
    std::string uuid;
    auto status = _accountService->CheckUser(userAlias, passwordSHA256, uuid);
    if (status != VipUserStatusOK) {
        std::cout << "check user failed: " << status << std::endl;
        return status;
    }
    
    std::cout << "check user in DB success, uuid=" << uuid << std::endl;

    _accessService->DeleteUserTicket(uuid);     // make old ticket invalid
    TokenInfo tokenInfo;
    status = _accessService->CreateUserTicket(uuid, passwordSHA256, tokenInfo);
        if (status != VipUserStatusOK) {
        std::cout << "create user ticket failed: status" << status << std::endl;
        return status;
    }

    ticket.uuid = uuid;
    ticket.tokenInfo = tokenInfo;

    return VipUserStatusOK;
}

VipUserStatus VipUserServer::CheckLogin(std::string uuid, std::string accessToken)
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

