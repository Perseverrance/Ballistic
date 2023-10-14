cmake_minimum_required(VERSION 3.24.2)
project(project_b)

set(CMAKE_CXX_STANDART 20)

find_package(GTest REQUIRED)

add_executable(Google_Tests_run
        test.cpp)

add_test(Google_Tests_run COMMAND test.cpp)

target_link_libraries(Google_Tests_run GTest::gtest_main)