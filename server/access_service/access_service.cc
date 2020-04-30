#include "access_service.h"

#include "crypt_helper.h"
#include "crypt_plus.h"

using namespace vipuser;

const uint32_t ACCESS_TOKEN_EXPIRES_IN_SECS = 2 * 3600;
const uint32_t REFRESH_TOKEN_EXPIRES_IN_SECS = 30 * 24 * 3600;

struct RefreshTokenInfo
{
    std::string uuid;
    uint64_t timestamp;
    uint64_t salt;
};


AccessService::AccessService()
{
    _redis = new Redis("127.0.0.1", 6379);
    _cryptPlus = new CryptPlus("defaultKey");
}

AccessService::~AccessService()
{
    delete _redis;
    delete _cryptPlus;
}

VipUserStatus AccessService::CreateUserTicket(std::string uuid, std::string key, TokenInfo& ticket) 
{
    if (uuid.size() == 0 || key.size() == 0) {
        return VipUserStatusErrorParam;
    }

    auto refreshToken = MakeRefreshToken(uuid, key);
    if (refreshToken.size() == 0) {
        return VipUserStatusTicketError;
    }
    auto accessToken = md5(refreshToken);

    if (_redis->addEntity(uuid, accessToken, refreshToken) != 0) {
        return VipUserStatusRedisError;
    }
    
    ticket.refreshToken = refreshToken;
    ticket.accessToken = md5(refreshToken);
    ticket.accessTokenExpiredInSecs = ACCESS_TOKEN_EXPIRES_IN_SECS;
    ticket.refreshTokenExpiredInSecs = REFRESH_TOKEN_EXPIRES_IN_SECS;

    return VipUserStatusOK;
}

VipUserStatus AccessService::DeleteUserTicket(std::string uuid) 
{
    if (uuid.size() == 0) {
        return VipUserStatusErrorParam;
    }

    if (_redis->removeEntities(uuid) != 0) {
        std::cout << "delete faild for uuid=" << uuid << std::endl;
        // DO NOT return
    }
    
    return VipUserStatusOK;
}

std::string AccessService::MakeRefreshToken(std::string uuid, std::string key) 
{
    RefreshTokenInfo rti;
    rti.uuid = uuid;
    rti.timestamp = getCurrentTimeMills();
    rti.salt = genRandom();

    _cryptPlus->setKey(key);
    return _cryptPlus->EncryptAEScbc(&rti, sizeof(rti));
}
