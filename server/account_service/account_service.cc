#include "account_service.h"
#include "vipuser_common.h"

using namespace vipuser;



VipUserStatus readUserDetail(std::string uuid, AccountDetailInfo &accountDetail) {

    return VipUserStatusOK;
}



AccountService::AccountService()
{
    std::string connectName = "dbname = vipuser user = postgres password = nicE_Work-878 \
      hostaddr = 127.0.0.1 port = 5432";

    _psql = new Psql(connectName);
}

AccountService::~AccountService() 
{
    delete _psql;
}

VipUserStatus AccountService::AddUser(std::string userAlias, std::string passwordSHA256, std::string& outUuid) 
{
    int exist = CheckUserAliasExist(userAlias);
    if (exist < 0) {
        return VipUserStatusError;
    } 
    if (exist == 1) {
        return VipUserStatusAccountExist;
    }

    AccountDetailInfo accountDetail;
    accountDetail.userAlias = userAlias;
    accountDetail.passwordSum = passwordSHA256;
    accountDetail.uuid = generateUuid();
    accountDetail.createTimeMills = getCurrentTimeMills();
    if (_psql->AddUser(accountDetail) != 0) {
        std::cout << "add user to DB failed" << std::endl;
        return VipUserStatusDBFailed;
    }

    outUuid =  accountDetail.uuid;
    return VipUserStatusOK;
}

VipUserStatus AccountService::CheckUser(std::string userAlias, std::string passwordSHA256, std::string& outUuid)
{
    AccountDetailInfo accountDetail;
    if (_psql->QueryUserByAlias(userAlias, accountDetail) != 0) {
        std::cout << "query user failed" << std::endl;
        return VipUserStatusAccountNotExist;
    }

    if (accountDetail.passwordSum != passwordSHA256) {
        std::cout << "wrong password: server=" << accountDetail.passwordSum << ", client=" << passwordSHA256 << std::endl;
        return VipUserStatusErrorPassword;
    }

    outUuid = accountDetail.uuid;
    return VipUserStatusOK;
}


int AccountService::CheckUserAliasExist(std::string userAlias) 
{
    AccountDetailInfo accountDetail;
    return _psql->QueryUserByAlias(userAlias, accountDetail) == 0;
}



