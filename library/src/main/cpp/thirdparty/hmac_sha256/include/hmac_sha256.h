// include/hmac_sha256.h
#ifndef HMAC_SHA256_H
#define HMAC_SHA256_H

#include <cstddef>
#ifdef __cplusplus
extern "C" {
#endif

// HMAC-SHA256计算函数
size_t hmac_sha256(
    const void* key, const size_t keylen,
    const void* data, const size_t datalen,
    void* out, const size_t outlen
);

// 十六进制字符串转换函数
//void bytes_to_hex(const void* data, size_t len, char* hex);

#ifdef __cplusplus
}
#endif

#endif // HMAC_SHA256_H
