#include "account_server.h"
#include "vipuser_common.h"

#include "crypt_helper.h"
#include "crypt_plus.h"

using namespace vipuser;

struct RefreshTokenInfo
{
    std::string uuid;
    uint64_t timestamp;
    uint64_t salt;
};


VipUserStatus readUserDetail(std::string uuid, AccountDetailInfo &accountDetail) {

    return VipUserStatusOK;
}


const uint PASSWORD_SUM_LENGTH = 256;


AccountServer::AccountServer(Redis &redis, Psql &psql):_redis(redis),_psql(psql) {
    _cryptPlus = new CryptPlus("defaultKey");

    std::cout << "world" << std::endl;
    std::cout << "uuid=" << generateUuid() << std::endl;

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

VipUserStatus AccountServer::CreateAccount(std::string userId, std::string passwordSHA256, UserTicket &ticket)
{

    if (AccountExist(userId)) {
        return VipUserStatusAccountExist;
    }

    if (passwordSHA256.size() != PASSWORD_SUM_LENGTH) {
        return VipUserStatusErrorFormat;
    }

    std::string uuid = generateUuid();
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

VipUserStatus AccountServer::Login(std::string userId, std::string passwordSHA256, UserTicket &ticket)
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

VipUserStatus AccountServer::Relogin(std::string refreshToken, UserTicket &ticket)
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
