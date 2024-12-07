cmake_minimum_required(VERSION 3.5)
project(Project10)

set(CMAKE_C_COMPILER "gcc")
set(CMAKE_CXX_COMPILER "g++")

file(GLOB_RECURSE SOURCES "src/*.cpp" "include/*.h")
include_directories(${PROJECT_NAME} PRIVATE include)
source_group(${PROJECT_NAME} STATIC ${SOURCES})

add_executable(${PROJECT_NAME} src/main.cpp ${SOURCES})