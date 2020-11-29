cmake_minimum_required(VERSION 2.8.9)
project (TDD_testing)

add_executable(moneycalc src/main.cpp)
add_executable(moneycalc_test test/main.cpp)
target_link_libraries(moneycalc_test gtest pthread)

