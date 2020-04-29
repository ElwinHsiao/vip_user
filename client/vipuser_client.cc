#include "vipuser_client.h"

#include <grpcpp/grpcpp.h>

using namespace vipuser;


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


int VipUserClient::CreateAccount(std::string userAlias, std::string passwordSum)
{
    auto accountInfo = new vipuser_proto::AccountInfo();
    accountInfo->set_useralias(userAlias);
    accountInfo->set_passwordsha256(passwordSum);

    vipuser_proto::CreateAccountRequest request;
    request.set_allocated_accountinfo(accountInfo);

    grpc::ClientContext context;
    vipuser_proto::CreateAccountResponse response;
    grpc::Status status = _stub->CreateAcount(&context, request, &response);

    if (!status.ok()) {
        std::cout << "server response error: " << status.error_message() << std::endl;
        return -1;
    }

    std::cout << "response: resultCode=" << response.result().code() << ", message=" << response.result().message() << std::endl;

    return 0;
}

int VipUserClient::Login(std::string userAlias, std::string passwordSum)
{

    return 0;
}