cmake_minimum_required(VERSION 3.10)
project(ylibc C)

set(CMAKE_C_STANDARD 99)

include_directories(include)

# library
set(lib_srcs src/list.c)
add_library(yllibc STATIC ${lib_srcs})

# test
set(lib_tests test/test.c)
add_executable(yllibc-test ${lib_tests})
target_link_libraries(yllibc-test yllibc)

