cmake_minimum_required(VERSION 3.12)
project(Lab04)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(lab04_main src/main.cpp)
target_include_directories(lab04_main PRIVATE include)

find_package(GTest REQUIRED)

add_executable(lab04_tests 
    src/test_figures.cpp 
    src/test_array.cpp
)
target_include_directories(lab04_tests PRIVATE include)
target_link_libraries(lab04_tests GTest::gtest GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(lab04_tests)