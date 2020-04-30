
#include "redis_helper.h"
#include <string.h>
#include <string>
#include <stdio.h>

// #define CHECK_CONNECT \
//     if (_connect == NULL) return -1; \
//     if (_connect->err != 0)
  
using namespace vipuser;

bool safeRedisCommand(redisContext* context, redisReply **reply, const char *format, ...) {
    if (context == NULL || context->err != 0) {
        printf("pre-exec error: %s\n", (context == NULL ? "NULL" : context->errstr));
        return false;
    }

    va_list args;
    va_start(args, format);
    *reply = (redisReply*)redisvCommand(context, format, args);
    va_end(args);

    if (reply == NULL || context->err != 0) {
        printf("post-exec error: %s\n", context->errstr);
        return false;
    }

    return true;
}

Redis::Redis(std::string host, int port): _host(host), _port(port)
{
    _connect = redisConnect(host.c_str(), port);
    _reply = NULL;
}
 
Redis::~Redis()
{
    _connect = NULL;
    _reply = NULL;                
}

int Redis::addEntity(std::string uuid, std::string accessToken, std::string refreshToken)
{
    if (uuid.size() == 0 || accessToken.size() == 0 || refreshToken.size() == 0) {
        return -1;
    }
    auto key = uuid + "_" + accessToken;
    if (Set(key, refreshToken) != 0) {
        std::cout << "write error: key=" << key << std::endl;
        return -1;
    }

    return 0;
}

int Redis::removeEntities(std::string uuid)
{
    if (uuid.size() == 0) {
        return -1;
    }

    auto keyPattern = uuid + "_" + "*";
    if (Delete(keyPattern) != 0) {
        std::cout << "delete error: key=" << keyPattern << std::endl; 
    }

    return 0;
}


void Redis::AutoConnect()
{
    if (_connect == NULL) {
        Connect(_host, _port);
    }
}

int Redis::Connect(std::string host, int port)
{
    auto conn = redisConnect(host.c_str(), port);
    if (conn == NULL) {
        std::cout << "connect failed" << std::endl;
        return -1;
    }
    if (conn->err != 0) {
        printf("connect error: %s\n", conn->errstr);
        return -1;
    }

    _connect = conn;
    return 0;
}

int Redis::Get(std::string key, std::string& value)
{
    if (!safeRedisCommand(_connect, &_reply, "GET %s", key.c_str())) {
        return -1;
    }
    
    std::cout << "reply: type=" << _reply->type << ", len=" << _reply->len << std::endl;
    if (_reply->len == 0) {
        return -1;
    }

    if (_reply->type != REDIS_REPLY_STRING) {
        std::cout << "not string type: " << _reply->type << std::endl;
    }

    value = std::string(_reply->str);
    return 0;
}

int Redis::Set(std::string key, std::string value)
{
    if (!safeRedisCommand(_connect, &_reply, "SET %s %s", key.c_str(), value.c_str())) {
        return -1;
    }

    return 0;
}

int Redis::Get(std::string key, int64_t& value)
{
    if (!safeRedisCommand(_connect, &_reply, "GET %s", key.c_str())) {
        return -1;
    }
    
    std::cout << "reply: type=" << _reply->type << ", len=" << _reply->len << std::endl;
    if (_reply->len == 0) {
        return -1;
    }

    if (_reply->type != REDIS_REPLY_INTEGER) {
        std::cout << "not integer type: " << _reply->type << std::endl;
    }

    value = _reply->integer;
    return 0;
}

int Redis::Set(std::string key, int64_t value)
{
    if (!safeRedisCommand(_connect, &_reply, "SET %s %lld", key.c_str(), value)) {
        return -1;
    }

    return 0;
}

int Redis::Delete(std::string key)
{
    if (!safeRedisCommand(_connect, &_reply, "DEL %s", key.c_str())) {
        return -1;
    }

    return 0;
}

// bool Redis::Contains(std::string key) 
// {
//     return false;
// }

// void Redis::AppendToList(std::string key) 
// {
    
// }

// void Redis::SwitchDB(RedisDBIndex index) 
// {
    
// }