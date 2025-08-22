cmake_minimum_required(VERSION 3.14)

set(CMAKE_C_STANDARD 99)

# 对于 "CMAKE_INSTALL_<dir>" 标准安装目录
#include(GNUInstallDirs)

project(hmac_sha256 VERSION 1.0 LANGUAGES C CXX)

option(HMAC_SHA256_TESTS "Build unit tests" FALSE)
option(HMAC_SHA256_EXAMPLES "Build the examples" FALSE)

# 添加源文件列表到一个变量中，避免重复
set(SOURCES
  ${CMAKE_CURRENT_SOURCE_DIR}/sha256.c
  ${CMAKE_CURRENT_SOURCE_DIR}/hmac_sha256.c
)

add_library(hmac_sha256_static STATIC ${SOURCES})
set_target_properties(hmac_sha256_static PROPERTIES OUTPUT_NAME hmac_sha256_static)

add_library(hmac_sha256_shared SHARED ${SOURCES})
set_target_properties(hmac_sha256_shared PROPERTIES OUTPUT_NAME hmac_sha256_shared)
set_target_properties(hmac_sha256_shared PROPERTIES VERSION ${PROJECT_VERSION} SOVERSION 1)

# 将头文件包含目录添加到接口，使其可用于链接库的目标
target_include_directories(hmac_sha256_static INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(hmac_sha256_shared INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})


# 安装静态库和动态库
install(TARGETS hmac_sha256_static hmac_sha256_shared
  LIBRARY DESTINATION "${CMAKE_INSTALL_LIBDIR}"
  ARCHIVE DESTINATION "${CMAKE_INSTALL_LIBDIR}"
)

# 安装头文件
install(FILES
  ${CMAKE_CURRENT_SOURCE_DIR}/hmac_sha256.h
  DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}"
)

if (HMAC_SHA256_TESTS)
  enable_testing()
  add_subdirectory(tests)
endif()

if(HMAC_SHA256_EXAMPLES)
  add_subdirectory(examples)
endif()
