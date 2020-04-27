#ifndef _CRYPT_PLUS_H_
#define _CRYPT_PLUS_H_

#include <iostream>
#include <openssl/evp.h>


namespace vipuser {

class CryptPlus {
public:
    CryptPlus(std::string key);
    ~CryptPlus();
    std::string EncryptAEScbc(std::string text);
    std::string DecryptAEScbc(std::string text);

private:
    std::string _key;
    EVP_CIPHER_CTX *_ctx;
};


}

#endif