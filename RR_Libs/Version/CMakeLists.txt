project(Version)

add_library(${PROJECT_NAME} STATIC
        Version.h
        Version.cpp
        )

target_include_directories(${PROJECT_NAME} PUBLIC ../.)





