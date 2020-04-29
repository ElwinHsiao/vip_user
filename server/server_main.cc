#include <iostream>
#include "account_server.h"

using namespace vipuser;

int main(int argc, char** argv) {
  std::cout << "hello" << std::endl;

  Redis redis;
  Psql psql;
  AccountServer server(redis, psql);

  UserTicket ticket;
  server.CreateAccount("", "", ticket);
  // std::cout << "uuid=" << Genuuid() << std::endl;
  return 0;
}
