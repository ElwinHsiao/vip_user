#ifndef _ACCESS_SERVICE_H_
#define _ACCESS_SERVICE_H_

#include <iostream>
#include "redis_helper.h"
#include "crypt_plus.h"


namespace vipuser {


class AccessService {
public:
    AccessService(Redis redis);
    ~AccessService();
    //int isLogined(std::string userAlias);

private:
    Redis &_redis;
    CryptPlus *_cryptPlus;

    std::string MakeRefreshToken(std::string uuid, uint64_t timestamp, std::string key);

};


}
#endif