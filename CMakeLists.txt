cmake_minimum_required(VERSION 3.10)
project(SingletonTest)

set(CMAKE_CXX_STANDARD 17)

# Add Google Test
add_subdirectory(lib/googletest)
include_directories(lib/googletest/googletest/include)

# Add your source files
add_library(singleton singleton.cpp)

# Add your tests
add_executable(runTests test/singleton_test.cpp)
target_link_libraries(runTests singleton gtest gtest_main)
