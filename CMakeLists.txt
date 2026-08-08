cmake_minimum_required(VERSION 3.20)

project(cpp_ci_demo LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(cal
    src/cal.cpp
)

target_include_directories(cal
    PUBLIC include
)

target_compile_options(cal PRIVATE
    -Wall
    -Wextra
    -Wpedantic
)

add_executable(app
    src/main.cpp
)

target_link_libraries(app PRIVATE cal)

enable_testing()

add_executable(test_cal
    tests/test_cal.cpp
)

target_link_libraries(
    test_cal
    PRIVATE cal
)

add_test(
    NAME cal_test
    COMMAND test_cal
)