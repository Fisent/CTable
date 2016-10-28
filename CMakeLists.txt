cmake_minimum_required(VERSION 3.6)
project(CTable)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp CTable.cpp CTable.h)
add_executable(CTable ${SOURCE_FILES})