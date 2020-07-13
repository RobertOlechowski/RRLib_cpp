project(Async)

add_library(${PROJECT_NAME} STATIC
        AsyncTaskBase.cpp
        AsyncTaskBase.h
        TasksCollection.cpp
        TasksCollection.h
        ThreadSync.cpp
        ThreadSync.h
        )


target_link_libraries(${PROJECT_NAME} INTERFACE Common)
target_include_directories(${PROJECT_NAME} PUBLIC ../.)





