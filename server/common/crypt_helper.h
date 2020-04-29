#ifndef _CRYPT_HELPER_H_
#define _CRYPT_HELPER_H_

#include <iostream>

std::string sha256(const std::string str);
int aes_encrypt(char *in, char *key, char *out);
int aes_decrypt(char *in, char *key, char *out);

#endif