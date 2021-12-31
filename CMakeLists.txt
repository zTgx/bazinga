cmake_minimum_required(VERSION 2.8.11)

set(BAZINGAS bazingas)
project(${BAZINGAS})


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -Wall -g")

link_directories(/home/ztgx/workspace/ssl-workplace/guomi/gmsslv3/build/lib)

aux_source_directory(./src SRCS)
add_executable(${BAZINGAS} ${SRCS})

include_directories(/home/ztgx/workspace/ssl-workplace/guomi/gmsslv3/include)
target_link_libraries(${BAZINGAS} libgmssl.so)


