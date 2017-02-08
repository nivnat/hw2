cmake_minimum_required(VERSION 3.6)
project(homework2)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES Rubiks/main.cpp Rubiks/Cube.cpp Rubiks/streamOps.cpp Rubiks/Cell.h Rubiks/Cube.h)
add_executable(homework2 ${SOURCE_FILES})