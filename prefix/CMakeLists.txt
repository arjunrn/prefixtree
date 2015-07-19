cmake_minimum_required(VERSION 2.8)
project(prefix)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
SET(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -O0 -DDEBUG -rdynamic -g")

set(SOURCE_FILES main.cpp)
add_executable(prefix ${SOURCE_FILES} prefix.cpp prefix.h)
