project(Common)

add_library(${PROJECT_NAME} STATIC
        Types.h
        macros.h
        NonCopyableNotMovable.h
        StlFlagsGuard.h
        StlFlagsGuard.cpp
        MinimumDelay.cpp
        MinimumDelay.h
        Converter.cpp Converter.h Round.h Asserts.h Asserts.cpp)

target_include_directories(${PROJECT_NAME} PUBLIC ../.)





