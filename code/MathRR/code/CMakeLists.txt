project(MathRR VERSION 1.0.1 LANGUAGES CXX)

project_init_rr()

add_library(${PROJECT_NAME} INTERFACE)

add_subdirectory(inc)
#add_subdirectory(src)

#target_link_libraries(${PROJECT_NAME} PUBLIC Common)

target_include_directories(${PROJECT_NAME} INTERFACE inc)





