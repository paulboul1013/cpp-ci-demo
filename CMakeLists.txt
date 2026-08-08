cmake_minimum_required(VERSION 3.20)

project(cpp_ci_demo LANGUAGES CXX)

# --------------------------------------------------
# C++ standard
# --------------------------------------------------

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)


# --------------------------------------------------
# GoogleTest
# --------------------------------------------------

include(FetchContent)

FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.17.0.zip
)

FetchContent_MakeAvailable(googletest)


# --------------------------------------------------
# Production library
# --------------------------------------------------

add_library(account_service
    src/account_service.cpp
)

target_include_directories(
    account_service
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_compile_options(
    account_service
    PRIVATE
        -Wall
        -Wextra
        -Wpedantic
)


# --------------------------------------------------
# Application
# --------------------------------------------------

add_executable(
    app
    src/main.cpp
)

target_link_libraries(
    app
    PRIVATE
        account_service
)


# --------------------------------------------------
# Testing
# --------------------------------------------------

enable_testing()

add_executable(
    test_account_service
    tests/test_account_service.cpp
)

target_link_libraries(
    test_account_service
    PRIVATE
        account_service
        GTest::gtest_main
)


# --------------------------------------------------
# GoogleTest + CTest integration
# --------------------------------------------------

include(GoogleTest)

gtest_discover_tests(
    test_account_service
)