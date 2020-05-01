#include "vipuser_client.h"
#include <chrono>
#include <grpcpp/grpcpp.h>
#include "picosha2.h"

#define DECLARE_RPC_PAIR(REQUEST, RESPONSE) \
    REQUEST request; RESPONSE response;

using namespace vipuser;

struct BaseCall
{
    grpc::ClientContext context;
    grpc::Status status;
    BaseCall() 
    {
        auto deadline = std::chrono::system_clock::now() + std::chrono::seconds(5);
        context.set_deadline(deadline);
    }

    void CallSink(VipUserClientSink *sink, ReplyResult &result)
    {
        if (sink == NULL) {
            std::cout << "no sink set: code=" << result.code << ", message=" << result.message << std::endl;
            return;
        }

        if (result.code != 0) {
            std::cout << "channel error: code=" << result.code << ", message=" << result.message << std::endl;
            UserTicket ticket;
            sink->OnCreateAccountEnd(result, ticket);
            return;
        }

        DoCallSink(sink, result);

    }

protected:
    virtual void DoCallSink(VipUserClientSink *sink, ReplyResult result) = 0;
};

inline vipuser_proto::AccountInfo* newAccountInfo(std::string userAlias, std::string passwordSum)
{
    auto accountInfo = new vipuser_proto::AccountInfo();
    accountInfo->set_useralias(userAlias);
    accountInfo->set_passwordsha256(passwordSum);
    return accountInfo;
}

typedef void (VipUserClientSink::*AccountCallBack)(ReplyResult&, UserTicket&);
template<typename RESPONSE>
void HandleCallSink(VipUserClientSink *sink, AccountCallBack callback, ReplyResult result, RESPONSE response)
{
    UserTicket ticket;
    if (!response.has_result()) {
        std::cout << "has no result" << std::endl;
        result = { -501, "has no result"};
        (sink->*callback)(result, ticket);
        return;
    }
    result.code = response.result().code();
    result.message = response.result().message();
    if (result.code != 0) {
        std::cout << "response error: code=" << result.code << ", message=" << result.message << std::endl;
        (sink->*callback)(result, ticket);
        return;
    }
    if (!response.has_tokeninfo()) {
        std::cout << "has no token" << std::endl;
        result = { -502, "has no token"};
        (sink->*callback)(result, ticket);
        return;
    }
    ticket.uuid = response.tokeninfo().uuid();
    ticket.accessToken = response.tokeninfo().accesstoken();
    ticket.refreshToken = response.tokeninfo().refreshtoken();
    std::cout << "response normal: uuid=" << ticket.uuid << ", accessToken=" << ticket.accessToken << std::endl;
    (sink->*callback)(result, ticket);
}

struct CreateAccountCall: public BaseCall//<vipuser_proto::CreateAccountRequest, vipuser_proto::CreateAccountResponse>
{
    DECLARE_RPC_PAIR(vipuser_proto::CreateAccountRequest, vipuser_proto::CreateAccountResponse)

    CreateAccountCall(std::string userAlias, std::string passwordSum) 
    {
        request.set_allocated_accountinfo(newAccountInfo(userAlias, passwordSum));
    }

protected:
    void DoCallSink(VipUserClientSink *sink, ReplyResult result)
    {
        HandleCallSink(sink, &VipUserClientSink::OnCreateAccountEnd, result, response);
    }
};

struct LoginCall: public BaseCall
{
    DECLARE_RPC_PAIR(vipuser_proto::LoginRequest, vipuser_proto::LoginResponse)

    LoginCall(std::string userAlias, std::string passwordSum)// : CreateAccountCall(userAlias, passwordSum) 
    {
        request.set_allocated_accountinfo(newAccountInfo(userAlias, passwordSum));
    }


protected:
    void DoCallSink(VipUserClientSink *sink, ReplyResult result)
    {
        HandleCallSink(sink, &VipUserClientSink::OnLoginEnd, result, response);
    }
};




std::string sha256Of(std::string src_str) {
    std::vector<unsigned char> hash(32);
    picosha2::hash256(src_str.begin(), src_str.end(), hash.begin(), hash.end());
    std::string hex_str = picosha2::bytes_to_hex_string(hash.begin(), hash.end());
    return hex_str;
}

VipUserClient::VipUserClient(std::string &serverAddr, std::string &sslKey) : _sink(NULL), _cq(NULL)//, _isWorkThreadStarted(false)
{
    grpc::SslCredentialsOptions sslOpts;
    sslOpts.pem_root_certs = sslKey;

    auto channel = grpc::CreateChannel(serverAddr, grpc::SslCredentials(sslOpts));
    _stub = vipuser_proto::VipUser::NewStub(channel);
}

VipUserClient::~VipUserClient()
{

}

int VipUserClient::CreateAccount(std::string userAlias, std::string password)
{
    if (userAlias.size() == 0) {
        std::cout << "empty userAlias" << std::endl;
        return -1;
    }
    if (password.size() == 0) {
        std::cout << "empty password" << std::endl;
        return -1;
    }

    std::string passwordSum = sha256Of(password);
    auto *call = new CreateAccountCall(userAlias, passwordSum);

    std::unique_ptr<grpc::ClientAsyncResponseReader<vipuser_proto::CreateAccountResponse>> rpc(
        _stub->AsyncCreateAcount(&call->context, call->request, GetQueue()));
    rpc->Finish(&call->response, &call->status, (void *)call);
    return 0;
}

int VipUserClient::Login(std::string userAlias, std::string password)
{
    if (userAlias.size() == 0) {
        std::cout << "empty userAlias" << std::endl;
        return -1;
    }
    if (password.size() == 0) {
        std::cout << "empty password" << std::endl;
        return -1;
    }

    std::string passwordSum = sha256Of(password);
    auto *call = new LoginCall(userAlias, passwordSum);
    std::unique_ptr<grpc::ClientAsyncResponseReader<vipuser_proto::LoginResponse>> rpc(
        _stub->AsyncLogin(&call->context, call->request, GetQueue()));

    rpc->Finish(&call->response, &call->status, (void *)call);
    return 0;
}

int VipUserClient::ReLogin(std::string accessToken)
{


    return 0;
}
int VipUserClient::Logout(std::string accessToken)
{



    return 0;
}

void VipUserClient::StartWorkerThread()
{
    if (_cq != NULL) {
        return;
    }
    _cq = new grpc::CompletionQueue;

    std::thread thread(&VipUserClient::HandleResponseQueue, this);
    thread.detach();
}

void VipUserClient::StopWorkerThread()
{
    if (_cq != NULL) {
        std::cout << "Ask to stop The Worker Thread" << std::endl;
        _cq->Shutdown();
    }
}

inline ReplyResult composeResult(bool ok, grpc::Status status) {
    if (!ok) {
        return {-1, "not ok"};
    }

    if (!status.ok()) {
        return {status.error_code(), status.error_message()};
    }

    return {0, "ok"};
}

void VipUserClient::HandleResponseQueue()
{
    std::cout << "RPC Response Thread Start" << std::endl;

    bool shutdown = false;
    void* got_tag;
    bool ok = false;
    while (!shutdown)
    {
        auto deadline = std::chrono::system_clock::now() + std::chrono::milliseconds(100); 
        auto status = _cq->AsyncNext(&got_tag, &ok, deadline);
        if (status == grpc::CompletionQueue::SHUTDOWN) {
            break;
        }
        if (status == grpc::CompletionQueue::TIMEOUT) {
            continue;
        }
        if (status != grpc::CompletionQueue::GOT_EVENT) {
            continue;
        } 

        std::cout << "got a response: ok=" << ok << std::endl;

        BaseCall* call = static_cast<BaseCall*>(got_tag);
        ReplyResult result = composeResult(ok, call->status);
        call->CallSink(_sink, result);
        
        //std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }
    
    std::cout << "RPC Response Thread End" << std::endl;
}

