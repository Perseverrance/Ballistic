project(sofa)

file(GLOB_RECURSE src *.cpp *.h *.hpp)

add_library(${PROJECT_NAME} INTERFACE ${src})

target_include_directories(${PROJECT_NAME} INTERFACE third_party)