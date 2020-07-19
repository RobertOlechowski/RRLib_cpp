project(SysInfo
        VERSION 1.0.1
        LANGUAGES CXX
        )

project_init_rr()

add_library(${PROJECT_NAME} STATIC)
add_subdirectory(inc)
add_subdirectory(src)

find_package(OpenCV)
if (OpenCV_FOUND)
    add_compile_definitions(OPENCV_VERSION=${OpenCV_VERSION} WITH_OPENCV2)
endif()

find_package(Boost)
if (Boost_FOUND)
    add_compile_definitions(Boost_VERSION_STRING=${Boost_VERSION_STRING})
endif()

target_link_libraries(${PROJECT_NAME} PRIVATE MMalRR)


target_link_libraries(${PROJECT_NAME} PRIVATE Assert Others)
target_link_libraries(${PROJECT_NAME} PUBLIC Common Version)


target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/inc)





