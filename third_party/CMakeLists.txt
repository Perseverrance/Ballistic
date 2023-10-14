add_subdirectory(sofa)

if(COMPILE_WITH_TESTS)
    add_subdirectory(google_test)
    message(gtest)
endif()