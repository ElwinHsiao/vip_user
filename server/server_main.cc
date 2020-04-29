#include <iostream>
#include "account_server.h"

#include "protos/vipuser.grpc.pb.h"

using namespace vipuser;

class VipUserGRPC final : public vipuser_proto::VipUser::Service
{
  grpc::Status CreateAcount(::grpc::ServerContext *context, const ::vipuser_proto::CreateAccountRequest *request, ::vipuser_proto::CreateAccountResponse *response)
  {
    vipuser_proto::Result result;
    result.set_message("success");
    response->result = result;
    return grpc::Status::OK;
  }
  grpc::Status Login(::grpc::ServerContext *context, const ::vipuser_proto::LoginRequest *request, ::vipuser_proto::LoginResponse *response)
  {
    return grpc::Status::OK;
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
};

int main(int argc, char **argv)
{
  std::cout << "hello" << std::endl;

  Redis redis;
  Psql psql;
  AccountServer server(redis, psql);

  UserTicket ticket;
  server.CreateAccount("", "", ticket);
  // std::cout << "uuid=" << Genuuid() << std::endl;
  return 0;
}
