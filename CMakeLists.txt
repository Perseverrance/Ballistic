cmake_minimum_required(VERSION 3.24.2)
project(project_b)

set(CMAKE_CXX_STANDART 20)

add_subdirectory(third_party)
include_directories(third_party)

add_subdirectory(tests)
add_subdirectory(src)
include_directories(src)

if(WITH_TESTS)
    set(COMPILE_WITH_TESTS ON)
    enable_testing()
    add_subdirectory(tests)
    message("TESTING:  ON")
else()
    message("TESTING: OFF")
endif()

#target_link_libraries(${PROJECT_NAME} PUBLIC ballistic)