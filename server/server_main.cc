#include <iostream>
#include <fstream>
#include <sstream>
#include <thread>

#include <grpcpp/grpcpp.h>
#include <grpcpp/health_check_service_interface.h>
#include <grpcpp/ext/proto_server_reflection_plugin.h>

#include "vipuser_server.h"
#include "protos/vipuser.grpc.pb.h"

using namespace vipuser;


static inline vipuser_proto::Result* newResult(int code, std::string message) {
    auto result = new vipuser_proto::Result();
    result->set_code(code);
    result->set_message(message);
    return result;
}

class VipUserGRPC final : public vipuser_proto::VipUser::Service
{
public:
    grpc::Status CreateAcount(::grpc::ServerContext *context, const ::vipuser_proto::CreateAccountRequest *request, ::vipuser_proto::CreateAccountResponse *response)
    {
        return CreateOrLogin(true, context, request, response);
    }
    grpc::Status Login(::grpc::ServerContext *context, const ::vipuser_proto::LoginRequest *request, ::vipuser_proto::LoginResponse *response)
    {
        return CreateOrLogin(false, context, request, response);
    }
    grpc::Status Logout(::grpc::ServerContext *context, const ::vipuser_proto::LogoutRequest *request, ::vipuser_proto::LogoutResponse *response)
    {
        return grpc::Status::OK;
    }
    grpc::Status ReLogin(::grpc::ServerContext *context, const ::vipuser_proto::ReLoginRequest *request, ::vipuser_proto::ReLoginResponse *response)
    {
        return grpc::Status::OK;
    }
    grpc::Status DoBusiness(::grpc::ServerContext *context, const ::vipuser_proto::BusinessRequest *request, ::vipuser_proto::BusinessResponse *response)
    {
        return grpc::Status::OK;
    }

private:
    VipUserServer _vipUserServer;

    template <typename REQUEST, typename RESPONSE>
    grpc::Status CreateOrLogin(bool isCreate, ::grpc::ServerContext *context, const REQUEST request, RESPONSE response)
    {
        if (!request->has_accountinfo() || request->accountinfo().useralias().empty() || request->accountinfo().passwordsha256().empty()) {
            std::cout << "invalid account info" << std::endl;
            response->set_allocated_result(newResult(VipUserStatusErrorParam, "invalid account info"));
            return grpc::Status::OK;
        }
        
        auto userAlias = request->accountinfo().useralias();
        auto passwordSum = request->accountinfo().passwordsha256();


        std::string logPrefix = (isCreate ? "CreateAcount" : "Login");
        std::cout << logPrefix << ": userAlias=" << userAlias << ", passwordSum=" << passwordSum << std::endl;

        UserTicket ticket;
        VipUserStatus status;
        if (isCreate) {
            status = _vipUserServer.CreateAccount(userAlias, passwordSum, ticket);
        } else {
            status = _vipUserServer.Login(userAlias, passwordSum, ticket);
        }
        if (status != VipUserStatusOK) {
            response->set_allocated_result(newResult(status, "account error"));
            return grpc::Status::OK;
        }

        std::cout << logPrefix << ": uuid=" << ticket.uuid << ", accessToken=" << ticket.tokenInfo.accessToken << ", refreshToken=" << ticket.tokenInfo.refreshToken << std::endl;
        auto tokenInfo = new vipuser_proto::TokenInfo();
        tokenInfo->set_uuid(ticket.uuid);
        tokenInfo->set_accesstoken(ticket.tokenInfo.accessToken);
        tokenInfo->set_refreshtoken(ticket.tokenInfo.refreshToken);
        tokenInfo->set_accesstokenexpiresinsecs(ticket.tokenInfo.accessTokenExpiredInSecs);
        tokenInfo->set_accesstokenexpiresinsecs(ticket.tokenInfo.refreshTokenExpiredInSecs);
        response->set_allocated_tokeninfo(tokenInfo);

        response->set_allocated_result(newResult(VipUserStatusOK, "success"));

        return grpc::Status::OK;
    }

};

grpc::string ReadFile(char *filePath)
{
    std::ifstream ifile(filePath);
    std::ostringstream buf;
    char ch;
    while (buf && ifile.get(ch))
        buf.put(ch);

    return buf.str();
}

int main(int argc, char **argv)
{
    std::cout << "server is coming - _ - ..." << std::endl;

    // Redis redis;
    // Psql psql;
    // AccountService server(redis, psql);

    // UserTicket ticket;
    // server.CreateAccount("", "", ticket);
    // std::cout << "uuid=" << Genuuid() << std::endl;

    char *keyFilePath = getenv("VIP_USER_SEVER_KEY");
    char *crtFilePath = getenv("VIP_USER_SEVER_CRT");
    if (keyFilePath == NULL || crtFilePath == NULL)
    {
        std::cout << "no rsa key path" << std::endl;
        return -1;
    }

    auto key = ReadFile(keyFilePath);
    auto crt = ReadFile(crtFilePath);
    std::cout << "key=" << key << std::endl;

    grpc::SslServerCredentialsOptions sslOpts{};
    sslOpts.pem_key_cert_pairs.push_back(
        grpc::SslServerCredentialsOptions::PemKeyCertPair{
            key, crt});

    grpc::EnableDefaultHealthCheckService(true);
    grpc::reflection::InitProtoReflectionServerBuilderPlugin();

    std::string server_address("0.0.0.0:50051");
    grpc::ServerBuilder builder;
    builder.AddListeningPort(server_address, grpc::SslServerCredentials(sslOpts));

    VipUserGRPC service;
    builder.RegisterService(&service);

    std::unique_ptr<grpc::Server> server(builder.BuildAndStart());
    std::cout << "Server listening on " << server_address << std::endl;

    server->Wait();

    return 0;
}
