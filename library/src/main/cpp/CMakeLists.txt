# CMakeLists.txt
cmake_minimum_required(VERSION 3.4.1)
project(hmac_sha256_aki)

# 设置C++标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 设置AKI根路径
set(AKI_ROOT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/../../../oh_modules/@ohos/aki)
set(CMAKE_MODULE_PATH ${AKI_ROOT_PATH})
find_package(Aki REQUIRED)

# 源文件
set(SOURCES
    hmac_sha256_aki.cpp         # AKI包装器
)

# 创建共享库
add_library(hmac_sha256_aki SHARED ${SOURCES})

# 链接AKI库和预编译的so库
target_link_libraries(hmac_sha256_aki PUBLIC
    Aki::libjsbind
    ${CMAKE_CURRENT_SOURCE_DIR}/../../libs/${OHOS_ARCH}/libhmac_sha256_shared.so
)

# 包含头文件路径
target_include_directories(hmac_sha256_aki PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/hmac_sha256/include
)

# 设置输出目录
set_target_properties(hmac_sha256_aki PROPERTIES
    LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/../lib
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/../lib
)
