
cmake_minimum_required(VERSION 3.10)
project(StudyPlannerTemplate)

set(CMAKE_CXX_STANDARD 17)

add_executable(StudyPlanner
    main.cpp
    backend/Task.cpp
    backend/TaskManager.cpp
)

include_directories(backend)
