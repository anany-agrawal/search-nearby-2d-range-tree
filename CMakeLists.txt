cmake_minimum_required(VERSION 3.10)
project(search_nearby)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

add_executable(search_nearby
    src/main.cpp
    src/RangeTree.cpp
    src/PointDatabase.cpp
)
