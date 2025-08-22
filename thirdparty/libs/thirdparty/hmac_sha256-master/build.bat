@echo off
REM 设置CMake路径
set CMAKE_PATH="D:\Program Files\Huawei\DevEco Studio\sdk\default\openharmony\native\build-tools\cmake\bin\cmake.exe"
REM 设置Ninja路径
set NINJA_PATH="D:\Program Files\Huawei\DevEco Studio\sdk\default\openharmony\native\build-tools\cmake\bin\ninja.exe"
REM 设置工具链文件路径
set TOOLCHAIN_FILE="D:\Program Files\Huawei\DevEco Studio\sdk\default\openharmony\native\build\cmake\ohos.toolchain.cmake"

REM 运行CMake命令，并传递所有参数
%CMAKE_PATH% -G Ninja -B out -DCMAKE_TOOLCHAIN_FILE=%TOOLCHAIN_FILE% -DCMAKE_MAKE_PROGRAM=%NINJA_PATH% -DCMAKE_BUILD_WITH_INSTALL_RPATH=true %*

REM 示例输出，可以通过 ./build.bat -DOHOS_ARCH=arm64-v8a 来指定架构
REM 这将生成如下命令：
REM "D:\Program Files\Huawei\DevEco Studio\sdk\default\openharmony\native\build-tools\cmake\bin\cmake.exe" -G Ninja -B out -DCMAKE_TOOLCHAIN_FILE="D:\Program Files\Huawei\DevEco Studio\sdk\default\openharmony\native\build\cmake\ohos.toolchain.cmake" -DCMAKE_MAKE_PROGRAM="D:\Program Files\Huawei\DevEco Studio\sdk\default\openharmony\native\build-tools\cmake\bin\ninja.exe" -DCMAKE_BUILD_WITH_INSTALL_RPATH=true -DOHOS_ARCH=arm64-v8a
