project(Version
        VERSION 1.0.1
        LANGUAGES CXX
        )

project_init_rr()

add_library(${PROJECT_NAME} STATIC)

add_subdirectory(inc)
add_subdirectory(src)


target_link_libraries(${PROJECT_NAME} PRIVATE Common Others)

target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/inc)





