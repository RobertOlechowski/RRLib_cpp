project(Assert_DemoApp VERSION 1.0.1 LANGUAGES CXX)

project_init_rr()

add_executable(${PROJECT_NAME})

target_sources(${PROJECT_NAME} PRIVATE
        main.cpp
        )

target_link_libraries(${PROJECT_NAME} PRIVATE Assert)





