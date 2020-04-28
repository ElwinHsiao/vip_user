#ifndef _PSQL_HELPER_H_
#define _PSQL_HELPER_H_

#include <iostream>
#include "pqxx/pqxx"

namespace vipuser {

class Psql {
public:

    Psql();
    ~Psql();

private:
    pqxx::connection *_conn;
    int Connect();
    void DisConnect();

    int CreateUserDetailTable();
};

}


#endif