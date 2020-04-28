#include "psql_helper.h"

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
        pqxx::work W(*_conn);

        /* Execute SQL query */
        W.exec(sql);
        W.commit();
        std::cout << "Table created successfully" << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}