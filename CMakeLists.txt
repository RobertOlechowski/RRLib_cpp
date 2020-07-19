cmake_minimum_required(VERSION 3.13.0 FATAL_ERROR)
project(RRLib VERSION 1.0.1 LANGUAGES CXX)

list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/_cmake)

function(project_init_rr)
    message(NOTICE " Project: ${PROJECT_NAME}  ${PROJECT_SOURCE_DIR}")
    configure_file (${CMAKE_SOURCE_DIR}/_cmake/cmake_gen.h.in ${PROJECT_SOURCE_DIR}/gen/cmake_gen.h)
endfunction()

add_subdirectory(code/Common)
add_subdirectory(code/Assert)
add_subdirectory(code/Others)
add_subdirectory(code/Version)
add_subdirectory(code/SysInfo)
add_subdirectory(code/MathRR)
add_subdirectory(code/Async)
add_subdirectory(code/Containers)
add_subdirectory(code/MMalRR)








