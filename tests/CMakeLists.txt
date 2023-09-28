cmake_minimum_required(VERSION 3.24.2)
project(project_b)

set(CMAKE_CXX_STANDART 17)

find_package(GTest REQUIRED)

add_executable(Google_Tests_run test.cpp
        test.cpp)

add_test(Google_Tests_run COMMAND test.cpp)
target_link_libraries(Google_Tests_run GTest::gtest_main)

#include(FetchContent)
#FetchContent_Declare(
#        googletest
#        URL https://github.com/google/googletest/archive/refs/tags/release-1.11.0.zip
#)
#FetchContent_MakeAvailable(googletest)
#add_library(GTest::GTest INTERFACE IMPORTED ../src/sum.h)
#target_link_libraries(GTest::GTest INTERFACE gtest_main)
#
#add_executable(
#        TESTs
#        test.cpp
#)
#
#target_link_libraries(
#        TESTs PRIVATE
#        GTest::GTest
#)