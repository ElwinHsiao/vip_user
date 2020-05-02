#include "../../../../../djinni/cpp/vipuser_service.hpp"

using namespace textsort;

namespace textsort {

class VipUserClientJni: public VipuserService
{
public:
    VipUserClientJni(std::shared_ptr<VipuserListener> & listener);
    virtual ~VipUserClientJni() {}

    virtual void create_account(const AccountInfo & account) override;

    virtual void login(const AccountInfo & account) override;

    virtual void re_login(const AccessTicket & ticket) override;

    virtual void logout(const AccessTicket & ticket) override;

    virtual void do_business(const AccessTicket & ticket, const std::vector<uint8_t> & request) override;

    /** Class Method */
    //static std::shared_ptr<VipuserService> create_with_listener(const std::shared_ptr<VipuserListener> & listener);

private:
    std::shared_ptr<VipuserListener> m_listener;
};

}