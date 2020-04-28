#include <iostream>
#include "vipuser_server.h"

using namespace vipuser;

int main(int argc, char** argv) {
  std::cout << "hello" << std::endl;

  Redis redis;
  Psql psql;
  AccountServer server(redis, psql);

  VipUserTicket ticket;
  server.CreateAccount("", "", ticket);
  // std::cout << "uuid=" << Genuuid() << std::endl;
  return 0;
}
