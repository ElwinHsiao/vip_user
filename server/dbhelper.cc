
#include "dbhelper.h"
#include <string.h>
#include <string>
#include <stdio.h>
  
using namespace vipuser;

Redis::Redis()
{
    _connect = NULL;
    _reply = NULL;
}
 
Redis::~Redis()
{
    _connect = NULL;
    _reply = NULL;                
}

bool Redis::Connect(std::string host, int port)
{
    _connect = redisConnect(host.c_str(), port);
    if (_connect == NULL) {
        std::cout << "connect failed" << std::endl;
        return 0;
    }
    if(_connect != NULL && _connect->err != 0)
    {
        printf("connect error: %s\n", _connect->errstr);
        return 0;
    }
    return 1;
}

std::string Redis::Get(std::string key)
{
    if (!isConnected()) {
        return "";
    }
    _reply = (redisReply*)redisCommand(_connect, "GET %s", key.c_str());
    if (_reply == NULL || _connect->err != 0) {
        printf("exec error: %s\n", _connect->errstr);
        return "";
    }
    
    std::cout << "reply: type=" << _reply->type << ", len=" << _reply->len << std::endl;
    if (_reply->len == 0) {
        return "";
    }

    if (_reply->type == REDIS_REPLY_INTEGER) {
        return std::to_string(_reply->integer);
    }

    if (_reply->type == REDIS_REPLY_STRING) {
        return std::string(_reply->str);
    }

    // std::string str = _reply->str;
    // freeReplyObject(_reply);
    return "str";
}

void Redis::Set(std::string key, std::string value)
{
    if (!isConnected()) {
        return;
    }
    _reply = (redisReply*)redisCommand(_connect, "SET %s %s", key.c_str(), value.c_str());
    if (_reply == NULL || _connect->err != 0) {
        printf("exec error: %s\n", _connect->errstr);
    }
}


bool Redis::Contains(std::string key) 
{
    
    return false;
}

void Redis::AppendToList(std::string key) 
{
    
}