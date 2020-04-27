#include "vipuser_server.h"

#include "boost/uuid/uuid.hpp"
#include "boost/uuid/uuid_io.hpp"
#include "boost/uuid/uuid_generators.hpp"

// #include "picosha2/picosha2.h"
#include <openssl/sha.h>

using namespace vipuser;

std::string AccountServer::Genuuid()
{
//    boost::uuids::uuid uuid = boost::uuids::random_generator()();
    boost::uuids::random_generator gen;
    boost::uuids::uuid uuid = gen();
    return boost::uuids::to_string(uuid);
}

std::string sha256(const std::string str)
{
	char buf[2];
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, str.c_str(), str.size());
    SHA256_Final(hash, &sha256);
    std::string NewString = "";
    for(int i = 0; i < SHA256_DIGEST_LENGTH; i++)
    {
        sprintf(buf,"%02x",hash[i]);
        NewString = NewString + buf;
    }
	return NewString;
}


AccountServer::AccountServer(Redis &redis):_redis(redis) {
    std::cout << "world" << std::endl;
    std::cout << "uuid=" << Genuuid() << std::endl;

    std::string src_str = "The quick brown fox jumps over the lazy dog";
    auto hex_str = sha256(src_str);

    // std::vector<unsigned char> hash(32);
    // picosha2::hash256(src_str.begin(), src_str.end(), hash.begin(), hash.end());
    // std::string hex_str = picosha2::bytes_to_hex_string(hash.begin(), hash.end());
    std::cout << "sha256=" << hex_str << std::endl;
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
