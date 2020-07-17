project(SysInfo)

add_library(${PROJECT_NAME} STATIC
        CompilerInfo.cpp
        CompilerInfo.h
        InfoEnums.h
        BitMode.h
        EnumToString.h
        EnumToString.cpp
        SystemInfo.cpp
        SystemInfo.h
        LibsInfo.cpp
        LibsInfo.h
        InfoPresenter.cpp
        InfoPresenter.h
        )

target_include_directories(${PROJECT_NAME} PUBLIC ../.)

target_link_libraries(${PROJECT_NAME} PRIVATE Common MMalRR)

find_package(OpenCV)
add_compile_definitions(OPENCV_VERSION=${OpenCV_VERSION} WITH_OPENCV2)

find_package(Boost)
if (Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
    add_compile_definitions(Boost_VERSION_STRING=${Boost_VERSION_STRING})
endif ()

target_link_libraries(${PROJECT_NAME} PUBLIC Version)
