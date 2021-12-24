cmake_minimum_required(VERSION 2.8.11)
project(TinyGmssl)


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")

link_directories(/home/ztgx/workspace/ssl-workplace/guomi/gmssl-v3-dev/build/lib)

aux_source_directory(./src SRCS)
add_executable(TinyGmssl ${SRCS})

include_directories(/home/ztgx/workspace/ssl-workplace/guomi/gmssl-v3-dev/include)
target_link_libraries(TinyGmssl libgmssl.so)


