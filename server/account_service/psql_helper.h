#ifndef _PSQL_HELPER_H_
#define _PSQL_HELPER_H_

#include <iostream>
#include "pqxx/pqxx"
#include "vipuser_common.h"

namespace vipuser {

class Psql {
public:

    Psql(std::string connectName);
    ~Psql();

    int AddUser(AccountDetailInfo &accountDetail);
    int QueryUserByAlias(std::string &userAlias, AccountDetailInfo &accountDetail);
    int UpdateUserPasswdSum(std::string &uuid, std::string passwdSum);

private:
    pqxx::connection *_conn;
    int Connect(std::string connectName);
    void DisConnect();

    int CreateUserDetailTable();
};

}


#endif