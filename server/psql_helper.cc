#include "psql_helper.h"


using namespace vipuser;

Psql::Psql()
{
    Connect();
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
        //_conn.close();
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }
}

void Psql::DisConnect() {
    //_conn->disconnect();
}
