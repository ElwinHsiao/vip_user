#ifndef _VIPUSER_COMMON_H_
#define _VIPUSER_COMMON_H_

#include <iostream>


struct AccountDetailInfo {
    std::string uuid;
    std::string userAlias;
    std::string passwordSum;
    std::string email;
    std::string phone;
    uint64_t createTimeMills;
    uint64_t index;     // the DB auto increate index;
};


#endif