cmake_minimum_required(VERSION 3.15)
project(students_management)

set(CMAKE_CXX_STANDARD 14)

if (MSVC)
    add_definitions(-D_CRT_SECURE_NO_WARNINGS)
endif ()

include_directories(include)

file(GLOB_RECURSE SOURCE_FILES src/*.cpp)
add_executable(${PROJECT_NAME} ${SOURCE_FILES})
