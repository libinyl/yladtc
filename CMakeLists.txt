cmake_minimum_required(VERSION 3.10)
project(yladtc C)

set(CMAKE_C_STANDARD 99)

include_directories(include)

# library
set(lib_srcs src/vector.c src/list.c)
add_library(yladtc STATIC ${lib_srcs})

# test
set(lib_tvector test/tvector.c)
set(lib_tlist test/tlist.c)

## test for vector
add_executable(yladtc-tvector ${lib_tvector})
target_link_libraries(yladtc-tvector yladtc)

## test for list
add_executable(yladtc-tlist ${lib_tlist})
target_link_libraries(yladtc-tlist yladtc)
