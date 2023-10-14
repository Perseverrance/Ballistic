project(ballistics)

file(GLOB_RECURSE src *.cpp *.h *.hpp)

add_library(ballistics INTERFACE ${src})

target_include_directories(ballistics INTERFACE Time)
target_link_libraries(ballistics INTERFACE sofa)