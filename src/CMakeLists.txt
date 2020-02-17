cmake_minimum_required (VERSION 3.8)

project (quicksort)

add_library(sort_algorithm STATIC sorting.cpp)

add_executable(quicksort main.cpp)
target_compile_options(quicksort PRIVATE -Wall -Wextra -Wpedantic)
target_link_libraries(quicksort PUBLIC sort_algorithm)
target_include_directories(quicksort PUBLIC "${PROJECT_BINARY_DIR}" "${PROJECT_SOURCE_DIR}/src")
