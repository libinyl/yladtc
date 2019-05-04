cmake_minimum_required(VERSION 3.10)
project(yladtc C)

set(CMAKE_C_STANDARD 99)

include_directories(include)

# library
set(lib_srcs src/list.c)
add_library(yladtc STATIC ${lib_srcs})

# test
set(lib_tests test/test.c)
add_executable(yladtc-test ${lib_tests})
target_link_libraries(yladtc-test yladtc)