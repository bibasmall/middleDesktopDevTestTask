cmake_minimum_required(VERSION 3.14)

project(PathMaker LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_CXX_STANDARD 17)

find_package(Qt6 REQUIRED COMPONENTS Core)

add_executable(PathMaker
  src/main.cpp
  src/pathMaker.h
)
target_link_libraries(PathMaker Qt6::Core)
