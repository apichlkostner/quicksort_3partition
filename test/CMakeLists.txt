cmake_minimum_required (VERSION 3.8)

# gtest
enable_testing()
find_package(GTest REQUIRED)
include(GoogleTest)

# enable multithreading for random stress test
add_definitions(-DMULTITHREADED)

add_executable(quicksort_test test_sorting.cpp test_stress.cpp test_test_helpers.cpp test_helpers.cpp)

target_compile_options(quicksort_test PRIVATE -Wall -Wextra -Wpedantic)
target_link_libraries(quicksort_test    PUBLIC GTest::GTest
                                        PUBLIC GTest::Main
                                        PUBLIC sort_algorithm
                                        PUBLIC pthread
                                        PUBLIC gcov)
gtest_discover_tests(quicksort_test)
