#include <string>
#include <openssl/md5.h>
#include <openssl/sha.h>
#include <openssl/aes.h>

#include "crypt_helper.h"


std::string md5(const std::string& src)
{
    MD5_CTX ctx;

    std::string md5_string;
    unsigned char md[16] = { 0 };
    char tmp[33] = { 0 };

    MD5_Init( &ctx );
    MD5_Update( &ctx, src.c_str(), src.size() );
    MD5_Final( md, &ctx );

    for( int i = 0; i < 16; ++i ) {   
        memset( tmp, 0x00, sizeof( tmp ) );
        sprintf( tmp, "%02x", md[i] );
        md5_string += tmp;
    }   
    return md5_string;
}

std::string sha256(const std::string str)
{
    char buf[2];
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, str.c_str(), str.size());
    SHA256_Final(hash, &sha256);
    std::string NewString = "";
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++)
    {
        sprintf(buf, "%02x", hash[i]);
        NewString = NewString + buf;
    }
    return NewString;
}



// use low level API of openssl
int aes_encrypt(char *in, char *key, char *out) //, int olen)可能会设置buf长度
{
    if (!in || !key || !out)
    {
        return 0;
    }
    unsigned char iv[AES_BLOCK_SIZE] = {0}; //加密的初始化向量, iv一般设置为全0,可以设置其他，但是加密解密要一样就行
    AES_KEY aes;
    if (AES_set_encrypt_key((unsigned char *)key, 128, &aes) < 0)
    {
        return 0;
    }
    int len = strlen(in);
    AES_cbc_encrypt((unsigned char *)in, (unsigned char *)out, len, &aes, iv, AES_ENCRYPT);
    return 1;
}

// use low level API of openssl
int aes_decrypt(char *in, char *key, char *out)
{
    if (!in || !key || !out)
    {
        return 0;
    }
    unsigned char iv[AES_BLOCK_SIZE] = {0};        //加密的初始化向量
    AES_KEY aes;
    if (AES_set_decrypt_key((unsigned char *)key, 128, &aes) < 0)
    {
        return 0;
    }
    int len = strlen(in);
    AES_cbc_encrypt((unsigned char *)in, (unsigned char *)out, len, &aes, iv, AES_DECRYPT);
    return 1;
}