cmake_minimum_required(VERSION 3.13)
project(EGNYTE)

add_subdirectory($ENV{gtest_DIR}/ gtest)
include_directories($ENV{gtest_DIR}/googletest/include $ENV{gtest_DIR}/googletest)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++0x")
set(CMAKE_CXX_STANDARD 14)


set(SOURCE_FILE
        Lib/OlechowskiTimer.cpp
        Lib/OlechowskiTimer.h
        Lib/TimerEnums.h )

set(TESTS_FILE
        Tests/PeriodTimerTests.cpp
        Tests/SingleTimerTests.cpp
        Tests/MixTimerTests.cpp
        Tests/ReadmeTests.cpp )


add_executable(consoleApp ${SOURCE_FILE} ConsoleApp/main.cpp )

add_executable(tests ${SOURCE_FILE} ${TESTS_FILE} )
target_link_libraries(tests gtest gtest_main)

