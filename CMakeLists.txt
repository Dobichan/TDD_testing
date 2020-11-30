cmake_minimum_required(VERSION 2.8.9)
project (TDD_testing)
set(CMAKE_CXX_STANDARD 17)

set (SOURCES src/Money.cpp
  )

set (TESTS test/testMoneyCalc.cpp
  )

include_directories(src)
add_executable(moneycalc src/main.cpp ${SOURCES})
add_executable(moneycalc_test test/main.cpp ${SOURCES} ${TESTS})
target_link_libraries(moneycalc_test gtest pthread)

