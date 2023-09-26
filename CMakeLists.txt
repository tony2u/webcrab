# CMakeList.txt: webcrab 的 CMake 项目，在此处包括源代码并定义
# 项目特定的逻辑。
#
cmake_minimum_required (VERSION 3.15)

# 如果支持，请为 MSVC 编译器启用热重载。
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()
if (POLICY CMP0091)
  cmake_policy(SET CMP0091 NEW)
endif()

project ("webcrab")

find_package(OPENSSL REQUIRED)
find_package(ZLIB REQUIRED)
find_package(HTTPLIB REQUIRED)

include_directories(
  ${cpp-httplib_INCLUDE_DIRS_RELEASE}
  ${openssl_INCLUDE_DIRS_RELEASE}
  ${zlib_INCLUDE_DIRS_RELEASE})
link_directories(
  ${openssl_LIB_DIRS_RELEASE}
  ${zlib_LIB_DIRS_RELEASE})
link_libraries(libssl libcrypto crypt32 ws2_32 zlib)

# 将源代码添加到此项目的可执行文件。
add_executable (webcrab "webcrab.cpp" "webcrab.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET webcrab PROPERTY CXX_STANDARD 20)
endif()

# TODO: 如有需要，请添加测试并安装目标。
