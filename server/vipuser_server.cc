#include "vipuser_server.h"

#include "boost/uuid/uuid.hpp"
#include "boost/uuid/uuid_io.hpp"
#include "boost/uuid/uuid_generators.hpp"

using namespace vipuser;

std::string Genuuid()
{
    boost::uuids::uuid a_uuid = boost::uuids::random_generator()();
    return boost::uuids::to_string(a_uuid);
}

AccountServer::AccountServer(Redis &redis):_redis(redis) {
    std::cout << "uuid=" << Genuuid() << std::endl;
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
