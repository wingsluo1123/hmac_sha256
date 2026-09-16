# hmac_sha256

## 简介

本软件是移植开源软件 [hmac_sha256](https://github.com/h5p9sl/hmac_sha256) 到 OpenHarmony 平台，提供 HMAC-SHA256 加密算法的 ArkTS/TypeScript 接口。

HMAC-SHA256 是一种基于 SHA256 哈希算法的消息认证码（HMAC）算法，广泛应用于数据完整性校验、身份认证、数字签名等场景。

## 下载安装

通过 ohpm 安装：

```bash
ohpm install @yyz116/hmac_sha256
```

OpenHarmony ohpm 环境配置等更多内容，请参考 [如何安装 OpenHarmony ohpm 包](https://gitee.com/openharmony-tpc/docs/blob/master/OpenHarmony_har_usage.md)

## 使用说明

### 1. 引入依赖

```typescript
import { HmacSha256Hex, HmacSha256Hash, HmacSha256HashBuffer } from '@yyz116/hmac_sha256';
```

### 2. API 说明

本库提供三个导出函数：

#### `HmacSha256Hex(key: string, data: string): string`

计算 HMAC-SHA256 并返回十六进制字符串。

**参数：**
- `key` - 密钥字符串
- `data` - 待加密的数据字符串

**返回值：**
- 64 字符的十六进制字符串（大写）

**示例：**
```typescript
const key = "my_secret_key";
const data = "hello world";
const hmac = HmacSha256Hex(key, data);
console.log(hmac); // 输出：AABBCCDD...（64位十六进制）
```

#### `HmacSha256Hash(key: string, data: string): number[]`

计算 HMAC-SHA256 并返回字节数组。

**参数：**
- `key` - 密钥字符串
- `data` - 待加密的数据字符串

**返回值：**
- 长度为 32 的数字数组（每个元素 0-255）

**示例：**
```typescript
const key = "my_secret_key";
const data = "hello world";
const hash = HmacSha256Hash(key, data);
console.log(hash); // 输出：[170, 187, 204, ...]（32个字节）
```

#### `HmacSha256HashBuffer(key: ArrayBuffer, data: ArrayBuffer): ArrayBuffer`

计算 HMAC-SHA256，接受和返回 ArrayBuffer 类型。

**参数：**
- `key` - 密钥的 ArrayBuffer
- `data` - 待加密数据的 ArrayBuffer

**返回值：**
- 长度为 32 字节的 ArrayBuffer

**示例：**
```typescript
import util from '@ohos.util';

const encoder = new util.TextEncoder();
const keyBuffer = encoder.encodeInto("my_secret_key").buffer;
const dataBuffer = encoder.encodeInto("hello world").buffer;

const resultBuffer = HmacSha256HashBuffer(keyBuffer, dataBuffer);

// 转换为十六进制显示
const view = new Uint8Array(resultBuffer);
let hex = '';
for (let i = 0; i < view.length; i++) {
    hex += view[i].toString(16).padStart(2, '0').toUpperCase();
}
console.log(hex);
```

### 3. 完整使用示例

```typescript
import { HmacSha256Hex, HmacSha256Hash, HmacSha256HashBuffer } from '@yyz116/hmac_sha256';
import util from '@ohos.util';

// 方式一：使用 HmacSha256Hex（最简单）
const key1 = "12345678";
const data1 = "test message";
const hexResult = HmacSha256Hex(key1, data1);
console.log('Hex result:', hexResult);

// 方式二：使用 HmacSha256Hash
const key2 = "12345678";
const data2 = "test message";
const hashArray = HmacSha256Hash(key2, data2);
console.log('Hash array:', hashArray);

// 方式三：使用 HmacSha256HashBuffer（二进制数据）
const encoder = new util.TextEncoder();
const keyBuf = encoder.encodeInto("12345678").buffer;
const dataBuf = encoder.encodeInto("test message").buffer;
const resultBuf = HmacSha256HashBuffer(keyBuf, dataBuf);
console.log('Result buffer length:', resultBuf.byteLength); // 32
```

## 注意事项

1. 密钥（key）建议至少 32 字节长度以获得最佳安全性
2. `HmacSha256Hex` 返回的十六进制字符串为大写格式
3. `HmacSha256HashBuffer` 适用于处理二进制数据或大文件
4. 在 ArkTS 中使用 ES6 模块规范（`import`），不是 CommonJS（`require`）

## 应用场景

- API 签名验证
- 数据完整性校验
- Token 生成
- 密码哈希
- Webhook 签名验证

## 开源协议

本项目基于原始 [hmac_sha256](https://github.com/h5p9sl/hmac_sha256) 项目移植，遵循相应开源协议。

## 贡献

欢迎提交 Issue 和 Pull Request。
