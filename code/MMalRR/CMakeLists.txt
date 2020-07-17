project(MMalRR)
set(CMAKE_CXX_STANDARD 17)

find_package(OpenCV REQUIRED)

FIND_LIBRARY(mmalvcclient_LIBS NAMES mmal_vc_client PATHS /opt/vc/lib REQUIRED)
set(REQUIRED_LIBRARIES ${REQUIRED_LIBRARIES} ${mmalvcclient_LIBS})

add_library(${PROJECT_NAME} STATIC
        MMalInfo.h
        MMalInfo.cpp
        MMALWrapper.h
        MMALWrapper.cpp
        MMalPoolWrapper.h
        MMalPoolWrapper.cpp
        MMALWrapperBase.h
        MMALWrapperBase.cpp
        MMalComponentBaseWrapper.h
        MMalConnectionWrapper.cpp
        MMalConnectionWrapper.h
        MMalCameraBaseWrapper.cpp
        MMalCameraBaseWrapper.h
        TypeConverter.h
        TypeConverter.cpp
        Metering.h
        AWB.h
        Effect.h
        Rotation.h
        Exposure.h
        MMalComponentBaseWrapper.cpp)

target_include_directories(${PROJECT_NAME} PRIVATE ${PROJECT_SOURCE_DIR}/../../External)
target_include_directories(${PROJECT_NAME} PRIVATE SYSTEM /opt/vc/include)


target_link_libraries(${PROJECT_NAME} PUBLIC ${OpenCV_LIBS} Version)
target_link_libraries(${PROJECT_NAME} PRIVATE Common ${REQUIRED_LIBRARIES})


target_include_directories(${PROJECT_NAME} PUBLIC ../.)
