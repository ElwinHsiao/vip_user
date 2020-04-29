#ifndef _VIPUSER_CLIENT_H_
#define _VIPUSER_CLIENT_H_

#include <iostream>
#include <thread>
#include <atomic>
// #include <future>


#include "protos/vipuser.grpc.pb.h"


namespace vipuser {

struct AccountInfo {
    std::string userAlias;
    std::string password;
};

struct UserTicket {
    std::string uuid;
    std::string accessToken;
    std::string refreshToken;
};

struct ReplyResult {
    int code;
    std::string message;
};


class VipUserClientSink {
public:
    virtual ~VipUserClientSink() { };
    virtual void OnCreateAccountEnd(ReplyResult &result, UserTicket &ticket) = 0;
    virtual void OnLoginEnd(ReplyResult &result, UserTicket &ticket) = 0;
    virtual void OnReLoginEnd(ReplyResult &result, UserTicket &ticket) = 0;
    virtual void OnLogoutEnd(ReplyResult &result) = 0;
};

class VipUserClient
{
public:
    VipUserClient(std::string &serverAddr, std::string &sslKey);
    ~VipUserClient();

    // AccountInfo &accountInfo, UserTicket &ticket
    int CreateAccount(std::string userAlias, std::string passwordSum);
    int Login(std::string userAlias, std::string passwordSum);
    int ReLogin(std::string accessToken);
    int Logout(std::string accessToken);

    inline void setVipUserClientSink(VipUserClientSink *sink) { _sink = sink; }
private:
    // std::string _serverAddr;
    // std::string _sslKey;
    std::unique_ptr<vipuser_proto::VipUser::Stub> _stub;
    grpc::CompletionQueue _cq;
    VipUserClientSink *_sink;

    std::atomic_bool _isWorkThreadStarted;

    void StartWorkerThread();
    void StopWorkerThread();
    void HandleResponseQueue();
};

}

#endif