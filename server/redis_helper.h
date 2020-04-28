#ifndef _DBHELPER_H_
#define _DBHELPER_H_

#include "hiredis/hiredis.h"
#include <iostream>


namespace vipuser {

enum RedisDBIndex {
    RedisDBIndexToken = 0,
    RedisDBIndexUser = 1,
};

class Redis
{
public:
 
    Redis();
 
    ~Redis();;
 
    bool Connect(std::string host, int port);
 
    std::string Get(std::string key);
    void Set(std::string key, std::string value);

    bool Contains(std::string key);
    void AppendToList(std::string key);

    void SwitchDB(RedisDBIndex index);
 
private:
    redisContext* _connect;
    redisReply* _reply;

    // inline bool isConnected() { return (this->_connect != NULL && this->_connect->err == 0); };
};
}

#endif  //_DBHELPER_H_
