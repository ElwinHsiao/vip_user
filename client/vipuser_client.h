#ifndef _VIPUSER_CLIENT_H_
#define _VIPUSER_CLIENT_H_

#include <iostream>

#include "protos/vipuser.grpc.pb.h"


namespace {

class VipUserClient
{
public:
    VipUserClient(std::string &serverAddr, std::string &sslKey);
    ~VipUserClient();

    int CreateAccount(std::string userAlias, std::string passwordSum);
    int Login(std::string userAlias, std::string passwordSum);
private:
    
};
    // std::string _serverAddr;
    // std::string _sslKey;
    std::unique_ptr<vipuser_proto::VipUser::Stub> _stub;

}

#endif