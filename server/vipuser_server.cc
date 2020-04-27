#include "vipuser_server.h"

#include "boost/uuid/uuid.hpp"
#include "boost/uuid/uuid_io.hpp"
#include "boost/uuid/uuid_generators.hpp"

#include "crypt_helper.h"
#include "crypt_plus.h"

using namespace vipuser;

std::string AccountServer::Genuuid()
{
//    boost::uuids::uuid uuid = boost::uuids::random_generator()();
    boost::uuids::random_generator gen;
    boost::uuids::uuid uuid = gen();
    return boost::uuids::to_string(uuid);
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


    /* A 256 bit key */
    unsigned char *key = (unsigned char *)"01234567890123456789012345678901";
    /* Message to be encrypted */
    std::string plainText = "This is a test.";
    std::cout << "original plainText=" << plainText << std::endl;
    CryptPlus cryptPlus("my_password123");
    std::string cipherText = cryptPlus.EncryptAEScbc(plainText);
    std::cout << "cipherText=|" << cipherText << "|" << std::endl;
    plainText = cryptPlus.DecryptAEScbc(cipherText);
    std::cout << "decrypted plainText=|" << plainText << "|" << std::endl;

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
