cmake_minimum_required(VERSION 3.15)
project(students_management)

include_directories(include)

file(GLOB_RECURSE SOURCE_FILES src/*.cpp)
add_executable(${PROJECT_NAME} ${SOURCE_FILES})
