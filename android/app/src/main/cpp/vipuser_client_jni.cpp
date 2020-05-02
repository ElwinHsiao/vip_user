#include "vipuser_client_jni.hpp"

//#include "../../../../../djinni/cpp/access_ticket.hpp"
//#include "../../../../../djinni/cpp/account_info.hpp"
//#include "../../../../../djinni/cpp/reply_result.hpp"
//#include "../../../../../djinni/cpp/token_info.hpp"
//#include "../../../../../djinni/cpp/vipuser_service.hpp"
//#include <iostream>

namespace textsort {
//using namespace vipuser;



    VipUserClientJni::VipUserClientJni(std::shared_ptr<VipuserListener> &listener) {
        this->m_listener = listener;
    }

    void VipUserClientJni::create_account(const AccountInfo &account) {

    }

    void VipUserClientJni::login(const AccountInfo &account) {

    }

    void VipUserClientJni::re_login(const AccessTicket &ticket) {

    }

    void VipUserClientJni::logout(const AccessTicket &ticket) {

    }

    void
    VipUserClientJni::do_business(const AccessTicket &ticket, const std::vector<uint8_t> &request) {

    }


/** Class Method */
    std::shared_ptr<VipuserService>
    VipuserService::create_with_listener(const std::shared_ptr<VipuserListener> &listener) {
        VipUserClientJni clientJni1();

        return nullptr;
//    auto clientJni = new VipUserClientJni(listener);
//    return std::make_shared<VipUserClientJni>(clientJni);
    }

//std::shared_ptr<VipuserService> create_with_listener(const std::shared_ptr<VipuserListener> & listener) {
//    return nullptr;
//}

//static std::shared_ptr<VipuserService> VipUserClientJni::create_with_listener(const std::shared_ptr<VipuserListener> & listener)
//{
//    return std::make_shared<VipUserClientJni>(listener);
//}
}