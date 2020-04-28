#include "vipuser_server.h"

#include <random>

#include "boost/uuid/uuid.hpp"
#include "boost/uuid/uuid_io.hpp"
#include "boost/uuid/uuid_generators.hpp"

#include "crypt_helper.h"
#include "crypt_plus.h"

using namespace vipuser;
struct RefreshTokenInfo
{
    std::string uuid;
    uint64_t timestamp;
    uint64_t salt;
};

struct AccountDetailInfo {
    std::string uuid;
    std::string userId;
    std::string passwordSum;
    std::string email;
    std::string phone;
    uint64_t createTimeMills;
    uint64_t index;     // the DB auto increate index;
};


uint64_t getCurrentTimeMills() {
    struct timeval tp;
    gettimeofday(&tp, NULL);
    return tp.tv_sec * 1000 + tp.tv_usec / 1000; 
}

uint64_t genRandom() {
    // obtain a seed from the system clock:
    unsigned seed1 = std::chrono::system_clock::now().time_since_epoch().count();

    std::mt19937 g1 (seed1); // mt19937 is a standard mersenne_twister_engine
    uint32_t u32Random = g1();
    std::cout << "A time seed produced: " << u32Random << std::endl;

    std::mt19937_64 g2 (seed1);
    uint64_t u64Random = g2();
    return u64Random;
}


VipUserStatus readUserDetail(std::string uuid, AccountDetailInfo &accountDetail) {

    return VipUserStatusOK;
}


const uint PASSWORD_SUM_LENGTH = 256;

std::string AccountServer::Genuuid()
{
//    boost::uuids::uuid uuid = boost::uuids::random_generator()();
    boost::uuids::random_generator gen;
    boost::uuids::uuid uuid = gen();
    return boost::uuids::to_string(uuid);
}


AccountServer::AccountServer(Redis &redis):_redis(redis) {
    _cryptPlus = new CryptPlus("defaultKey");

    std::cout << "world" << std::endl;
    std::cout << "uuid=" << Genuuid() << std::endl;

    std::string src_str = "The quick brown fox jumps over the lazy dog";
    auto hex_str = sha256(src_str);
    // std::vector<unsigned char> hash(32);
    // picosha2::hash256(src_str.begin(), src_str.end(), hash.begin(), hash.end());
    // std::string hex_str = picosha2::bytes_to_hex_string(hash.begin(), hash.end());
    std::cout << "sha256=" << hex_str << std::endl;


    /* A 256 bit key */
    //unsigned char *key = (unsigned char *)"01234567890123456789012345678901";
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
    delete _cryptPlus;
}

VipUserStatus AccountServer::CreateAccount(std::string userId, std::string passwordSHA256, VipUserTicket &ticket)
{

    if (AccountExist(userId)) {
        return VipUserStatusAccountExist;
    }

    if (passwordSHA256.size() != PASSWORD_SUM_LENGTH) {
        return VipUserStatusErrorFormat;
    }

    std::string uuid = Genuuid();
    auto status = StoreNewUser(uuid, userId, passwordSHA256);
    if (status != VipUserStatusOK) {
        return status;
    }

    std::string refreshToken = MakeRefreshToken(uuid, getCurrentTimeMills(), passwordSHA256);
    if (refreshToken.size() == 0) {
        return VipUserStatusError;
    }
    ticket.refreshToken = refreshToken;
    ticket.accessToken = sha256(refreshToken);

    return VipUserStatusOK;
}

VipUserStatus AccountServer::Login(std::string userId, std::string passwordSHA256, VipUserTicket &ticket)
{
    if (!AccountExist(userId)) {
        return VipUserStatusAccountNotExist;
    }

    // validate password
    // ...


    return VipUserStatusOK;
}

VipUserStatus AccountServer::CheckLogin(std::string accessToken)
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

bool AccountServer::AccountExist(std::string userId) {
    _redis.SwitchDB(RedisDBIndexUser);
    if (_redis.Contains(userId)) {
        return true;
    }

    // check db contains
    // ...

    return false;
}


VipUserStatus AccountServer::StoreNewUser(std::string uuid, std::string userId, std::string passwordSHA256)
{
    // store to db
    // ...
    return VipUserStatusOK;
}

std::string AccountServer::MakeRefreshToken(std::string uuid, uint64_t timestamp, std::string key) {
    RefreshTokenInfo rti;
    rti.uuid = uuid;
    rti.timestamp = timestamp;
    rti.salt = genRandom();

    _cryptPlus->setKey(key);
    return _cryptPlus->EncryptAEScbc(&rti, sizeof(rti));
}


// VipUserStatus WriteSession(std::string accessToken, std::string refreshToken) {
    
// }
