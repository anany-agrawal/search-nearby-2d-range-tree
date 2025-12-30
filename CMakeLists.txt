cmake_minimum_required(VERSION 3.10)
project(SearchNearby2D)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(include)

add_executable(search_nearby
    src/main.cpp
    src/RangeTree.cpp
)
