#ifndef _DBHELPER_H_
#define _DBHELPER_H_

#include "hiredis/hiredis.h"
#include <iostream>


namespace vipuser {

// enum RedisDBIndex {
//     RedisDBIndexToken = 0,
//     RedisDBIndexUser = 1,
// };

class Redis
{
public:
    Redis(std::string host, int port);
    ~Redis();
 
    int addEntity(std::string uuid, std::string accessToken, std::string refreshToken);
    int removeEntities(std::string uuid);
 
private:
    std::string _host;
    int _port;
    redisContext* _connect;
    redisReply* _reply;

    void AutoConnect();
    int Connect(std::string host, int port);
 
    int Get(std::string key, std::string& value);
    int Set(std::string key, std::string value);

    int Get(std::string key, int64_t& value);
    int Set(std::string key, int64_t value);
    int Delete(std::string key);

    // bool Contains(std::string key);
    // void AppendToList(std::string key);
    // void SwitchDB(RedisDBIndex index);
    // inline bool isConnected() { return (this->_connect != NULL && this->_connect->err == 0); };
};
}

#endif  //_DBHELPER_H_
