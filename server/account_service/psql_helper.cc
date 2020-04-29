#include "psql_helper.h"

#define CHECK_CONNECTION(conn)                           \
    if (!conn->is_open())                                \
    {                                                    \
        std::cout << "Can't open database" << std::endl; \
        return 1;                                        \
    }

using namespace vipuser;

Psql::Psql()
{
    Connect();
    CreateUserDetailTable();
}

Psql::~Psql()
{
    DisConnect();
}

int Psql::Connect()
{
    try
    {
        _conn = new pqxx::connection("dbname = vipuser user = postgres password = nicE_Work-878 \
      hostaddr = 127.0.0.1 port = 5432");
        if (_conn->is_open())
        {
            std::cout << "Opened database successfully: " << _conn->dbname() << std::endl;
        }
        else
        {
            std::cout << "Can't open database" << std::endl;
            return 1;
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}

void Psql::DisConnect()
{
    _conn->disconnect();
    _conn = NULL;
}

int Psql::CreateUserDetailTable()
{
    CHECK_CONNECTION(_conn);
    try
    {
        /* Create SQL statement */
        std::string sql = "CREATE TABLE IF NOT EXISTS AccountDetail("
                          "index   BIGSERIAL   UNIQUE,"
                          "uuid   CHAR(36)   PRIMARY KEY   NOT NULL,"
                          "user_alias   VARCHAR(48)   UNIQUE   NOT NULL,"
                          "passwd_sum   CHAR(64)   NOT NULL,"
                          "create_time   BIGINT   NOT NULL,"
                          "phone    VARCHAR(18),"
                          "email    VARCHAR(50) );";

        /* Create a transactional object. */
        pqxx::work work(*_conn);

        /* Execute SQL query */
        work.exec(sql);
        work.commit();
        std::cout << "Table created successfully" << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}

int Psql::AddUser(AccountDetailInfo &accountDetail)
{
    CHECK_CONNECTION(_conn);

    try
    {
        /* Create SQL statement */
        char sql[1024] = {0};
        sprintf(sql, "INSERT INTO accountdetail (uuid,user_alias,passwd_sum,create_time) "
                     "VALUES ('%s', '%s', '%s', %llu ); ",
                accountDetail.uuid.c_str(), accountDetail.userAlias.c_str(), accountDetail.passwordSum.c_str(), accountDetail.createTimeMills);

        /* Create a transactional object. */
        pqxx::work work(*_conn);

        /* Execute SQL query */
        work.exec(sql);
        work.commit();
        std::cout << "Insert user successfully" << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
        return -1;
    }

    return 0;
}

int Psql::QueryUserByAlias(std::string &userAlias, AccountDetailInfo &accountDetail)
{
    CHECK_CONNECTION(_conn);

    try
    {
        /* Create SQL statement */
        char sql[1024] = {0};
        sprintf(sql, "SELECT (uuid,user_alias,passwd_sum,create_time) from accountdetail "
                     "WHERE user_alias = %s",
                userAlias.c_str());

        /* Create a non-transactional object. */
        pqxx::nontransaction nonTrans(*_conn);

        /* Execute SQL query */
        pqxx::result queryResult(nonTrans.exec(sql));

        /* List down all the records */
        for (pqxx::result::const_iterator iterator = queryResult.begin(); iterator != queryResult.end(); ++iterator)
        {
            std::cout << "uuid = " << iterator[0].as<std::string>() << std::endl;
            std::cout << "user_alias = " << iterator[1].as<std::string>() << std::endl;
            std::cout << "passwd_sum = " << iterator[2].as<std::string>() << std::endl;
            std::cout << "create_time = " << iterator[3].as<uint64_t>() << std::endl;
        }

        if (queryResult.empty()) {
            std::cout << "user not exist" << std::endl;
            return -1;
        }

        if (queryResult.size() > 1) {
            std::cout << "exist same user alias";
            return -1;
        }

        pqxx::result::reference row = queryResult.front();
        accountDetail.uuid = row[0].as<std::string>();
        accountDetail.userAlias = row[1].as<std::string>();
        accountDetail.passwordSum = row[2].as<std::string>();
        accountDetail.createTimeMills = row[3].as<uint64_t>();
        std::cout << "Operation done successfully" << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
        return -1;
    }

    return 0;
}

int UpdateUserPasswdSum(std::string &uuid, std::string passwdSum)
{
    return 0;
}

//int Psql::