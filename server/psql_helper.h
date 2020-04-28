#ifndef _PSQL_HELPER_H_
#define _PSQL_HELPER_H_

#include <iostream>
#include "pqxx/pqxx"
#include "vipuser_common.h"

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
    int AddUser(AccountDetailInfo &accountDetail);
    int QueryUserByAlias(std::string &userAlias, AccountDetailInfo &accountDetail);
    int UpdateUserPasswdSum(std::string &uuid, std::string passwdSum);
};

}


#endif