cmake_minimum_required(VERSION 3.14)

set(CMAKE_AUTOMOC ON)
set(CMAKE_CXX_STANDARD 17)

set(OUTPUT_DIR_FOR_BIN ${PROJECT_SOURCE_DIR}/build/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${OUTPUT_DIR_FOR_BIN})

find_package(Qt6 REQUIRED COMPONENTS Core Network)

add_subdirectory(httpClient)
add_subdirectory(textStreamHttpClient)
