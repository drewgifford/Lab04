project(Lab04)
cmake_minimum_required(VERSION 3.10)
 
# Locate GTest
find_package(GTest REQUIRED)
find_package(Threads REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
add_compile_options(-std=c++17)
# Link runTests with what we want to test and the GTest and pthread library

add_executable(runMain main.cpp)