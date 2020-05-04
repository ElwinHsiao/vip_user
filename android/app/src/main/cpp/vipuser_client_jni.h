#include "vip_user_client_wrap.hpp"

namespace vipuser {

class VipUserWrapListener;
struct AccessTicket;
struct AccountInfo;

class VipUserClientJni: public VipUserClientWrap
{
public:
    VipUserClientJni();
    virtual ~VipUserClientJni() {}

    virtual void create_account(const AccountInfo & account) override;

    virtual void login(const AccountInfo & account) override;

    virtual void re_login(const AccessTicket & ticket) override;

    virtual void logout(const AccessTicket & ticket) override;

    virtual void do_business(const AccessTicket & ticket, const std::vector<uint8_t> & request) override;

    inline void setListener(const std::shared_ptr<VipUserWrapListener> & listener) { this->m_listener = listener; }
    /** Class Method */
    //static std::shared_ptr<VipUserClientWrap> create_with_listener(const std::shared_ptr<VipUserWrapListener> & listener);

private:
    std::shared_ptr<VipUserWrapListener> m_listener;
};

}