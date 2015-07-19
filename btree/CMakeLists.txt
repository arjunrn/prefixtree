cmake_minimum_required(VERSION 2.8)
project(Mina)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
SET(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -O0 -DDEBUG -rdynamic -g")

set(SOURCE_FILES main.cpp)
add_executable(Mina ${SOURCE_FILES} btree.cpp btree.h)
