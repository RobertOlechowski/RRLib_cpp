project(MMalRR VERSION 1.0.1 LANGUAGES CXX)

project_init_rr()

find_package(OpenCV REQUIRED)

FIND_LIBRARY(mmalvcclient_LIBS NAMES mmal_vc_client PATHS /opt/vc/lib REQUIRED)
set(REQUIRED_LIBRARIES ${REQUIRED_LIBRARIES} ${mmalvcclient_LIBS})

add_library(${PROJECT_NAME})

add_subdirectory(inc)
add_subdirectory(src)

target_include_directories(${PROJECT_NAME} PRIVATE SYSTEM /opt/vc/include)

target_link_libraries(${PROJECT_NAME} PUBLIC ${OpenCV_LIBS} Version Common)
target_link_libraries(${PROJECT_NAME} PRIVATE ${REQUIRED_LIBRARIES} Assert)

target_include_directories(${PROJECT_NAME} PUBLIC inc)





