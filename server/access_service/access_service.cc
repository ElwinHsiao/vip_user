#include "access_service.h"
#include "vipuser_common.h"

#include "crypt_helper.h"
#include "crypt_plus.h"

using namespace vipuser;


AccessService::AccessService(Redis redis): _redis(redis)
{
    _cryptPlus = new CryptPlus("defaultKey");
}

AccessService::~AccessService()
{
    delete _cryptPlus;
}

std::string AccessService::MakeRefreshToken(std::string uuid, uint64_t timestamp, std::string key) {
    RefreshTokenInfo rti;
    rti.uuid = uuid;
    rti.timestamp = timestamp;
    rti.salt = genRandom();

    _cryptPlus->setKey(key);
    return _cryptPlus->EncryptAEScbc(&rti, sizeof(rti));
}
