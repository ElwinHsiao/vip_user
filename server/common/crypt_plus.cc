#include "crypt_plus.h"
#include "vipuser_common.h"

#include <string>
#include <openssl/conf.h>
#include <openssl/err.h>


using namespace vipuser;

int initialize();
int encrypt(EVP_CIPHER_CTX *ctx, const unsigned char *plaintext, int plaintext_len, const unsigned char *key, unsigned char *ciphertext);
int decrypt(EVP_CIPHER_CTX *ctx, const unsigned char *ciphertext, int ciphertext_len, const unsigned char *key, unsigned char *plaintext);

CryptPlus::CryptPlus(std::string key): _key(key)
{
    initialize();
    _ctx = EVP_CIPHER_CTX_new();
}

CryptPlus::~CryptPlus() 
{
    EVP_CIPHER_CTX_free(_ctx);
}

std::string CryptPlus::EncryptAEScbc(std::string text)
{
    return EncryptAEScbc(text.c_str(), text.size());
}

std::string CryptPlus::EncryptAEScbc(const void *buffer, size_t bufLen) {
    unsigned char outtext[4096] = {0};
    int len = encrypt(_ctx, (const unsigned char *)buffer, bufLen, (const unsigned char *)(_key.c_str()), outtext);
    if (len <= 0) {
        return "";
    }

    std::string hexString = toHex(outtext, len);
    return hexString;
}

std::string CryptPlus::DecryptAEScbc(std::string text)
{
    unsigned char *cipherdata[4096] = {0};
    int dataLen = fromHex(text, cipherdata);
    unsigned char outtext[4096] = {0};
    int len = decrypt(_ctx, (const unsigned char *)cipherdata, dataLen, (const unsigned char *)_key.c_str(), outtext);
    if (len <= 0) {
        return "";
    }

    return std::string((char *)outtext, len);
}

int initialize() 
{
    static bool isInit = false;
    if (isInit) return 0;
    isInit = true;
    
    /* Initialise the library */
    ERR_load_crypto_strings();
    OpenSSL_add_all_algorithms();
    OPENSSL_config(NULL);

    return 0;
}

int encrypt(EVP_CIPHER_CTX *ctx, const unsigned char *plaintext, int plaintext_len, const unsigned char *key, unsigned char *ciphertext)
{
    if (NULL == ctx) {
        return -2;
    }
    if (1 != EVP_CIPHER_CTX_reset(ctx)) {
        ERR_print_errors_fp(stderr);
        return -1;
    }

    int len;

    int ciphertext_len;

    /* Initialise the encryption operation. IMPORTANT - ensure you use a key
     * In this example we are using 256 bit AES (i.e. a 256 bit key). 
     */
    if (1 != EVP_EncryptInit_ex(ctx, EVP_aes_256_ecb(), NULL, key, NULL)) {
        ERR_print_errors_fp(stderr);
        return -1;
    }

    /* Provide the message to be encrypted, and obtain the encrypted output.
     * EVP_EncryptUpdate can be called multiple times if necessary
     */
    if (1 != EVP_EncryptUpdate(ctx, ciphertext, &len, plaintext, plaintext_len)) {
        ERR_print_errors_fp(stderr);
        return -1;
    }
    ciphertext_len = len;

    /* Finalise the encryption. Further ciphertext bytes may be written at
     * this stage.
     */
    if (1 != EVP_EncryptFinal_ex(ctx, ciphertext + len, &len)) {
        ERR_print_errors_fp(stderr);
        return -1;
    }
    ciphertext_len += len;

    return ciphertext_len;
}

int decrypt(EVP_CIPHER_CTX *ctx, const unsigned char *ciphertext, int ciphertext_len, const unsigned char *key, unsigned char *plaintext)
{
    if (NULL == ctx) {
        return -2;
    }

    if (!EVP_CIPHER_CTX_reset(ctx)) {
        return -1;
    }

    int len;

    int plaintext_len;

    /* Initialise the decryption operation. IMPORTANT - ensure you use a key
     * In this example we are using 256 bit AES (i.e. a 256 bit key). The
     */
    if (1 != EVP_DecryptInit_ex(ctx, EVP_aes_256_ecb(), NULL, key, NULL))
        return -1;

    /* Provide the message to be decrypted, and obtain the plaintext output.
     * EVP_DecryptUpdate can be called multiple times if necessary
     */
    if (1 != EVP_DecryptUpdate(ctx, plaintext, &len, ciphertext, ciphertext_len))
        return -1;
    plaintext_len = len;

    /* Finalise the decryption. Further plaintext bytes may be written at
     * this stage.
     */
    if (1 != EVP_DecryptFinal_ex(ctx, plaintext + len, &len))
        return -1;
    plaintext_len += len;

    return plaintext_len;
}
