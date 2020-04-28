/*
 *
 * Copyright 2015 gRPC authors.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */

#include <iostream>
#include <memory>
#include <string>

#include <grpcpp/grpcpp.h>
#include <grpcpp/health_check_service_interface.h>
#include <grpcpp/ext/proto_server_reflection_plugin.h>

// #ifdef BAZEL_BUILD
// #include "examples/protos/helloworld.grpc.pb.h"
// #else
#include "helloworld.grpc.pb.h"
// #endif

#include <fstream>
#include <sstream>
#include <iostream>

#include "redis_helper.h"
using namespace vipuser;


using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::Status;
using helloworld::HelloRequest;
using helloworld::HelloReply;
using helloworld::Greeter;



grpc::string ReadFile(char *filePath) {
  std::ifstream ifile(filePath);
  std::ostringstream buf;
  char ch;
  while(buf&&ifile.get(ch))
    buf.put(ch);

  return buf.str();
}

// Logic and data behind the server's behavior.
class GreeterServiceImpl final : public Greeter::Service {
  Status SayHello(ServerContext* context, const HelloRequest* request,
                  HelloReply* reply) override {
    std::string prefix("Hello ");
    std::cout << "handle request: name=" << request->name() << std::endl;
    reply->set_message(prefix + request->name());
    return Status::OK;
  }
};

void RunServer() {
  Redis *redisClient = new Redis();
  redisClient->Connect("127.0.0.1", 6379);
  const auto userId = "userAAA";
  auto pass = redisClient->Get(userId);
  std::cout << "pass before set: " << pass << std::endl;
  // redisClient->Set(userId, "hahahaha ok ya !");
  // pass = redisClient->Get(userId);
  // std::cout << "pass after set: " << pass << std::endl;


  char *keyFilePath = getenv("VIP_USER_SEVER_KEY");
  char *crtFilePath = getenv("VIP_USER_SEVER_CRT");
  if (keyFilePath == NULL || crtFilePath == NULL) {
    std::cout << "no rsa key path" << std::endl;
    return;
  } 

  auto key = ReadFile(keyFilePath);
  auto crt = ReadFile(crtFilePath);

  grpc::SslServerCredentialsOptions sslOpts{};
  sslOpts.pem_key_cert_pairs.push_back(
    grpc::SslServerCredentialsOptions::PemKeyCertPair {
      key, crt
    }
  );


  std::string server_address("0.0.0.0:50051");
  GreeterServiceImpl service;


  grpc::EnableDefaultHealthCheckService(true);
  grpc::reflection::InitProtoReflectionServerBuilderPlugin();
  ServerBuilder builder;
  // Listen on the given address without any authentication mechanism.
  builder.AddListeningPort(server_address, grpc::SslServerCredentials(sslOpts));
  // Register "service" as the instance through which we'll communicate with
  // clients. In this case it corresponds to an *synchronous* service.
  builder.RegisterService(&service);
  // Finally assemble the server.
  std::unique_ptr<Server> server(builder.BuildAndStart());
  std::cout << "Server listening on " << server_address << std::endl;

  // Wait for the server to shutdown. Note that some other thread must be
  // responsible for shutting down the server for this call to ever return.
  server->Wait();
}

int main(int argc, char** argv) {
  RunServer();

  return 0;
}
