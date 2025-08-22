# jsbn

## 简介
   本软件是移植开源软件 [jsbn](https://github.com/andyperlitch/jsbn) 源码在OpenHarmony上进行功能适配，在OpenHarmony上已支持原库jsbn的功能。
   jsbn（JavaScript BigInteger Library）是一个用于JavaScript环境中的大整数（BigInteger）计算的开源库。在JavaScript中，原生的数据类型Number对于非常大的整数（超过Number.MAX_SAFE_INTEGER，大约为9007199254740991）无法提供精确表示和运算。jsbn库就是为了弥补这一不足而设计的，它提供了对大整数的各种数学运算的支持，包括加、减、乘、除、模运算以及比较、位操作等。
   这个库主要被用于那些需要处理加密算法、大数计算或者精确数学运算的场景，例如RSA、椭圆曲线加密（ECC）和其他涉及大整数操作的密码学应用。通过jsbn，开发者可以在浏览器环境中高效地进行大整数的精确计算，而不受JavaScript原生数值类型的限制。

## 下载安装
```shell
ohpm  install @yyz116/jsbn 
```
OpenHarmony ohpm 环境配置等更多内容，请参考[如何安装 OpenHarmony ohpm 包](https://gitee.com/openharmony-tpc/docs/blob/master/OpenHarmony_har_usage.md)
## 使用说明
1. 引入依赖
 ```
最新版本支持
   import { jsbn } from '@yyz116/jsbn' 或者
   import jsbn from '@yyz116/jsbn'
 ```
2. 使用
```ts
  import jsbn from '@yyz116/jsbn'
  var BigInteger = jsbn.BigInteger;
  var bi = new BigInteger('91823918239182398123');
  console.log(bi.bitLength()); // 67
```
3. 注意事项 在ets中使用的是es6的模块使用规范，使用import而不是require
# jsbn: javascript big number

[Tom Wu's Original Website](http://www-cs-students.stanford.edu/~tjw/jsbn/)

I felt compelled to put this on github and publish to npm. I haven't tested every other big integer library out there, but the few that I have tested in comparison to this one have not even come close in performance. I am aware of the `bi` module on npm, however it has been modified and I wanted to publish the original without modifications. This is jsbn and jsbn2 from Tom Wu's original website above, with the module pattern applied to prevent global leaks and to allow for use with node.js on the server side.

## Usage

```js
var BigInteger = require('jsbn').BigInteger;

var bi = new BigInteger('91823918239182398123');
console.log(bi.bitLength()); // 67
```

## API

### `bi.toString([radix]) => string`

Returns a string representing the BigInteger `bi`.

+ `radix` - Optional. An integer between 2 and 36 specifying the base to use for representing numeric values.

If the `radix` is not specified, the preferred `radix` is assumed to be 10.

### `bi.negate() => BigInteger`

Returns a new `BigInteger` equal to the negation of `bi`.

### `bi.abs() => BigInteger`

Returns a `BigInteger` equal to the absolute value of `bi`.

*note: if the `bi` is a positive value, it will be returned as is, otherwise a new instance of `BigInteger` is returned.*

### `bi.compareTo(other) => number`

Compare to `BigInteger`s. The return value will be a negative JavaScript number if `bi` is less than `other`, a positive number if `bi` is greater than `other`, and `0` if `bi` and `other` represents the same integer.

### `bi.bitLength() => number`

Returns the number of bits used to store `bi` as a JavaScript number.

### `bi.mod(m) => BigInteger`

Returns a `BigInteger` with the value of (`bi` mod `m`).

### `bi.modPow(exponent, m) => BitInteger`

Returns a `BigInteger` with the value of (`bi`<sup>`exponent`</sup> mod `m`).

### bi.modPowInt



### bi.clone



### bi.intValue



### bi.byteValue



### bi.shortValue



### bi.signum



### bi.toByteArray



### bi.equals



### bi.min



### bi.max



### bi.and



### bi.or



### bi.xor



### bi.andNot



### bi.not



### bi.shiftLeft



### bi.shiftRight



### bi.getLowestSetBit



### bi.bitCount



### bi.testBit



### bi.setBit



### bi.clearBit



### bi.flipBit



### bi.add



### bi.subtract



### bi.multiply



### bi.divide



### bi.remainder



### bi.divideAndRemainder



### bi.modPow



### bi.modInverse



### bi.pow



### bi.gcd



### bi.isProbablePrime
