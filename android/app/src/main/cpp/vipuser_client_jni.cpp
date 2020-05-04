#include "vipuser_client_jni.h"
#include <iostream>

#include "account_info.hpp"
#include "access_ticket.hpp"
#include "token_info.hpp"
#include "reply_result.hpp"
#include "vip_user_wrap_listener.hpp"

//#include "../../../../../djinni/generated/cpp/access_ticket.hpp"
//#include "../../../../../djinni/cpp/account_info.hpp"
//#include "../../../../../djinni/cpp/reply_result.hpp"
//#include "../../../../../djinni/cpp/token_info.hpp"
//#include "../../../../../djinni/cpp/vipuser_service.hpp"
//#include <iostream>

namespace vipuser {
//using namespace vipuser;



    VipUserClientJni::VipUserClientJni() {
        
    }

    void VipUserClientJni::create_account(const AccountInfo &account) {
        std::cout << "create_account: userName=" << account.user_name << std::endl;
    }

    void VipUserClientJni::login(const AccountInfo &account) {
        std::cout << "login: userName=" << account.user_name << std::endl;
    }

    void VipUserClientJni::re_login(const AccessTicket &ticket) {
        std::cout << "re_login: uuid=" << ticket.uuid << std::endl;
    }

    void VipUserClientJni::logout(const AccessTicket &ticket) {
        std::cout << "logout: uuid=" << ticket.uuid << std::endl;
    }

    void
    VipUserClientJni::do_business(const AccessTicket &ticket, const std::vector<uint8_t> &request) {
        std::cout << "do_business: uuid=" << ticket.uuid << ", byteLen=" << request.size() << std::endl;
    }


/** Class Method */
    std::shared_ptr<VipUserClientWrap>
    VipUserClientWrap::create_with_listener(const std::shared_ptr<VipUserWrapListener> &listener) {
        auto clientJni = std::make_shared<VipUserClientJni>();
        clientJni->setListener(listener);
        return clientJni;
//    return nullptr;
        // return std::make_shared<VipUserClientJni>(listener);
    }

//std::shared_ptr<VipUserClientWrap> create_with_listener(const std::shared_ptr<VipuserListener> & listener) {
//    return nullptr;
//}

//static std::shared_ptr<VipUserClientWrap> VipUserClientJni::create_with_listener(const std::shared_ptr<VipuserListener> & listener)
//{
//    return std::make_shared<VipUserClientJni>(listener);
//}
}