file(GLOB_RECURSE src *.c)
add_library(sofa STATIC ${src}
        ../../tests/test.cpp
        ../../tests/eu.cpp)

