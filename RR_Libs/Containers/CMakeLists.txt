project(Containers)

add_library(${PROJECT_NAME} INTERFACE
        )

target_link_libraries(${PROJECT_NAME} INTERFACE Common)
target_include_directories(${PROJECT_NAME} INTERFACE ../.)





