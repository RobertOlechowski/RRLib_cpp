cmake_minimum_required(VERSION 3.16)
project(RR_Utils_Cpp)

set(CMAKE_CXX_STANDARD 14)

include_directories(Common)
include_directories(Common/Src)
include_directories(IntervalContainer/Src)
include_directories(RR_Timer/Src)

add_executable(RR_Utils_Cpp
        Common/Src/NonCopyable.h
        Common/Src/NonCopyableNotMoveable.h
        Common/Src/Types.h
        IntervalContainer/Src/IntervalMap.h
        IntervalContainer/Tests/tests.cpp
        RR_Timer/ConsoleApp/main.cpp
        RR_Timer/Src/OlechowskiTimer.cpp
        RR_Timer/Src/OlechowskiTimer.h
        RR_Timer/Src/TimerEnums.h
        RR_Timer/Tests/MixTimerTests.cpp
        RR_Timer/Tests/PeriodTimerTests.cpp
        RR_Timer/Tests/ReadmeTests.cpp
        RR_Timer/Tests/SingleTimerTests.cpp main.cpp)
