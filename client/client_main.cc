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

class ClientSink : public VipUserClientSink {
    void OnCreateAccountEnd(ReplyResult &result, UserTicket &ticket)
    {
        std::cout << "OnCreateAccountEnd: result={code=" << result.code << ", message=" << result.message << "}" << std::endl;
    }

    void OnLoginEnd(ReplyResult &result, UserTicket &ticket)
    {
        std::cout << "OnLoginEnd: result={code=" << result.code << ", message=" << result.message << "}" << std::endl;
    }
    void OnReLoginEnd(ReplyResult &result, UserTicket &ticket)
    {

    }
    void OnLogoutEnd(ReplyResult &result)
    {

    }
};

int main(int argc, char **argv)
{
    std::string userName = "user1";
    bool isLogin = false;
    if (argc > 1) {
        userName = std::string(argv[1]);
    }
    if (argc > 2) {
        isLogin = true;
    }
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

    std::string password = "mypassword1";
    client.setVipUserClientSink(new ClientSink());
    if (isLogin) {
        std::cout << "Login" << std::endl;
        client.Login(userName, password);
    } else {
        std::cout << "CreateAccount" << std::endl;
        client.CreateAccount(userName, password);
    }

    std::this_thread::sleep_for(std::chrono::seconds(10));   // wait the response
    client.ShutdownImmediately();
    std::this_thread::sleep_for(std::chrono::microseconds(200));    // wait worker thread shutdown

    return 0;
}