// hmac_sha256_aki.cpp
#include <aki/jsbind.h>
#include "hmac_sha256.h"
#include <string>
#include <vector>

// 十六进制字符串转换函数
static void bytes_to_hex(const void* data, size_t len, char* hex) {
    const uint8_t* byte_data = static_cast<const uint8_t*>(data);
    for (size_t i = 0; i < len; ++i) {
        sprintf(hex + i * 2, "%02X", byte_data[i]);
    }
    hex[len * 2] = '\0';  // 确保字符串以 null 结尾
}

// 字符串输入版本
std::vector<uint8_t> HmacSha256Hash(const std::string& key, const std::string& data) {
    std::vector<uint8_t> output(32);
    size_t result_len = hmac_sha256(key.c_str(), key.length(), data.c_str(), data.length(), output.data(), output.size());
    output.resize(result_len);
    return output;
}

// ArrayBuffer输入版本
aki::ArrayBuffer HmacSha256HashBuffer( aki::ArrayBuffer& key,  aki::ArrayBuffer& data) {
    std::vector<uint8_t> output(32);
    size_t result_len = hmac_sha256(key.GetData(), key.GetLength(), data.GetData(), data.GetLength(), output.data(), output.size());
    aki::ArrayBuffer result(output.data(), result_len);
    return result;
}

// 十六进制输出版本
std::string HmacSha256Hex(const std::string& key, const std::string& data) {
    std::vector<uint8_t> output(32);
    size_t result_len = hmac_sha256(key.c_str(), key.length(), data.c_str(), data.length(), output.data(), output.size());
    
    char hex[65];
    bytes_to_hex(output.data(), result_len, hex);
    hex[64] = '\0';
    
    return std::string(hex);
}

// 注册AKI插件
JSBIND_ADDON(hmac_sha256_aki)

// 注册全局函数
JSBIND_GLOBAL() {
    JSBIND_FUNCTION(HmacSha256Hash);
    JSBIND_FUNCTION(HmacSha256HashBuffer);
    JSBIND_FUNCTION(HmacSha256Hex);
}
