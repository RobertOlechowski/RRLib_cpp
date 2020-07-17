project(Memory)

add_library(${PROJECT_NAME} STATIC
        Memory.h
        Memory.cpp
        )

target_include_directories(${PROJECT_NAME} PUBLIC ../.)

target_link_libraries(${PROJECT_NAME} PUBLIC Common)



