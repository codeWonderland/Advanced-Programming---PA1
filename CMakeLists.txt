cmake_minimum_required(VERSION 3.6)
project(PA1)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp CodeBook.cpp CodeBook.h functions.cpp functions.h)
add_executable(PA1 ${SOURCE_FILES})