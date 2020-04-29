#include <iostream>
#include "vipuser_client.h"

#include <fstream>
#include <sstream>
#include <iostream>

using namespace vipuser;

grpc::string ReadFile(char *filePath)
{
    std::ifstream ifile(filePath);
    std::ostringstream buf;
    char ch;
    while (buf && ifile.get(ch))
        buf.put(ch);

    return buf.str();
}

int main(int argc, char **argv)
{
    std::cout << "client is comming ^_^ ..." << std::endl;

    char *crtFilePath = getenv("VIP_USER_SEVER_CRT");
    if (crtFilePath == NULL)
    {
        std::cout << "no rsa key path" << std::endl;
        return -1;
    }
    auto crt = ReadFile(crtFilePath);
    std::cout << "crt=" << crt << std::endl;

    std::string serverAddr = "localhost:50051";
    VipUserClient client(serverAddr, crt);
    client.CreateAccount("elwin", "c20b711740111b5141a3780b7c548bfadedbf7cb78663847d70647c7b6a90aeb");

    return 0;
}