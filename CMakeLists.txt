cmake_minimum_required(VERSION 3.16)

project(LeetCode)

set(CMAKE_CXX_FLAGS "-Wall -Wextra -g -O1 -std=c++17")
file(GLOB CPP_HEADER_FILES *.h)
file(GLOB CPP_SOURCE_FILES *.cpp)
add_executable(LeetCode ${CPP_HEADER_FILES} ${CPP_SOURCE_FILES})
