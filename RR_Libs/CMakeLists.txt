project(RR_Libs)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

add_library(RR_Libs STATIC
        Common/Types.h
        Common/macros.h
        Common/NonCopyableNotMovable.h
        Common/StlFlagsGuard.h
        Common/StlFlagsGuard.cpp
        Common/MinimumDelay.cpp
        Common/MinimumDelay.h
#---------------
        Async/AsyncTaskBase.cpp
        Async/AsyncTaskBase.h
        Async/AsyncTasksCollection.cpp
        Async/AsyncTasksCollection.h
#---------------
        SysInfo/CompilerInfo.cpp
        SysInfo/CompilerInfo.h
        SysInfo/InfoEnums.h
        SysInfo/BitMode.h
        SysInfo/EnumToString.h
        SysInfo/EnumToString.cpp
        SysInfo/SystemInfo.cpp
        SysInfo/SystemInfo.h
        SysInfo/LibsInfo.cpp
        SysInfo/LibsInfo.h
#---------------
        Containers/CircularBuffer.h
        Containers/CircularBufferTs.h
        )

target_include_directories(RR_Libs PUBLIC .)

find_package(OpenCV REQUIRED )
target_link_libraries(RR_Libs PRIVATE Threads::Threads)

add_compile_definitions(OPENCV_VERSION=${OpenCV_VERSION} WITH_OPENCV2)
