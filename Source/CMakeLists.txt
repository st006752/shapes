cmake_minimum_required(VERSION 3.20)
project(shapes)

add_library(applib
    App.cpp
    Relations.cpp
    Storage.cpp
)

add_executable(shapes_app main.cpp)
target_link_libraries(shapes_app applib)

enable_testing()

include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)
FetchContent_MakeAvailable(googletest)

add_executable(shapes_tests ../Tests/test.cpp)
target_link_libraries(shapes_tests PRIVATE applib GTest::gtest_main)

add_test(NAME shapes_tests COMMAND shapes_tests)