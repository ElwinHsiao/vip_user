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
    std::string EncryptAEScbc(const void *buffer, size_t len);
    inline void setKey(std::string key) { _key = key; }
private:
    std::string _key;
    EVP_CIPHER_CTX *_ctx;
};


}

#endif