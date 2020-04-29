#include "vipuser_client.h"

#include <grpcpp/grpcpp.h>



VipUserClient::VipUserClient(std::string &serverAddr, std::string &sslKey)
{
    // _serverAddr = serverAddr;
    // _sslKey = sslKey;

    grpc::SslCredentialsOptions sslOpts;
    sslOpts.pem_root_certs = sslKey;

    auto channel = grpc::CreateChannel(serverAddr, grpc::SslCredentials(sslOpts));
    _stub = vipuser_proto::VipUser::NewStub(channel);
}

VipUserClient::~VipUserClient()
{

}


int CreateAccount(std::string userAlias, std::string passwordSum)
{
    // vipuser_proto::LoginRequest request;
    // vipuser_proto::AccountInfo accountInfo;
    // accountInfo.set_useralias(userAlias);
    // accountInfo.set_passwordsha256(passwordSum);
    // request.accountinfo = accountInfo;

    // vipuser_proto::LoginResponse response;
    // _stub->CreateAcount(_stub, request, &response);

    // std::cout << "response: resultCode=" << response.result->code << ", message=" << response.result->message;

    return 0;
}
int Login(std::string userAlias, std::string passwordSum)
{

    return 0;
}