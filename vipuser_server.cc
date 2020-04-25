#include "vipuser_server.h"

using namespace vipuser;


AccountServer::AccountServer(Redis &redis):_redis(redis) {
    
}

AccountServer::~AccountServer() {
    
}

VipUserStatus AccountServer::createAccount(std::string userId, std::string passwordHash, VipUserTicket &ticket)
{
    _redis.SwitchDB(RedisDBIndexUser);
    if (_redis.Contains(userId)) {
        return VipUserStatusError;
    }

    return VipUserStatusOK;
}

VipUserStatus AccountServer::Login(std::string userId, std::string passwordHash, VipUserTicket &ticket)
{
    return VipUserStatusOK;
}

VipUserStatus AccountServer::Logout(std::string accessToken)
{
    return VipUserStatusOK;
}

VipUserStatus AccountServer::Relogin(std::string refreshToken, VipUserTicket &ticket)
{
    return VipUserStatusOK;
}
