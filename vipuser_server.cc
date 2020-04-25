#include "vipuser_server.h"

using namespace vipuser;

static const uint DB_INDEX_LOGIN = 1;

AccountServer::AccountServer(Redis &redis):_redis(redis) {
    
}

AccountServer::~AccountServer() {
    
}

VipUserStatus AccountServer::createAccount(std::string userId, std::string passwordHash, VipUserTicket &ticket)
{
    //_redis.select(DB_INDEX_LOGIN)
    _redis.Get(userId);

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
