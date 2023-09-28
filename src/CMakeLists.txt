#cmake_minimum_required(VERSION 3.24.2)
#project(project_b)

file(GLOB_RECURSE HEADERS *.hpp *.h *.cpp)

add_library(ballistic INTERFACE ${HEADERS}
        time.h
        time.cpp)