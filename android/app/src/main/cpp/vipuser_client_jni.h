#include "vip_user_client_wrap.hpp"
#include "vipuser_client.h"

#include "account_info.hpp"
#include "access_ticket.hpp"
#include "vip_user_wrap_listener.hpp"


namespace vipuser {

class VipUserClientJni: public vipuser_djinni::VipUserClientWrap
{
public:
    VipUserClientJni();
    virtual ~VipUserClientJni();

    virtual void create_account(const vipuser_djinni::AccountInfo & account) override;

    virtual void login(const vipuser_djinni::AccountInfo & account) override;

    virtual void re_login(const vipuser_djinni::AccessTicket & ticket) override;

    virtual void logout(const vipuser_djinni::AccessTicket & ticket) override;

    virtual void do_business(const vipuser_djinni::AccessTicket & ticket, const std::vector<uint8_t> & request) override;

    inline void setListener(const std::shared_ptr<vipuser_djinni::VipUserWrapListener> & listener) { this->m_listener = listener; }
    /** Class Method */
    //static std::shared_ptr<VipUserClientWrap> create_with_listener(const std::shared_ptr<VipUserWrapListener> & listener);

private:
    std::shared_ptr<vipuser_djinni::VipUserWrapListener> m_listener;
    VipUserClient *_client;
};

}