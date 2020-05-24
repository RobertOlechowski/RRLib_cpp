cmake_minimum_required(VERSION 3.13)
project(Interval_container)


add_subdirectory($ENV{gtest_DIR}/ gtest)

include_directories($ENV{gtest_DIR}/googletest/include $ENV{gtest_DIR}/googletest)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++0x")
set(CMAKE_CXX_STANDARD 14)


add_executable(Interval_container_tests IntervalMap.h Tests/tests.cpp)

target_link_libraries(Interval_container_tests gtest gtest_main)