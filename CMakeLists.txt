cmake_minimum_required(VERSION 3.10)

project(coffee)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

#  1. GTEST

include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
    DOWNLOAD_EXTRACT_TIMESTAMP TRUE
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(googletest)

# 2. SOURCE CODE
add_library(GameLib
    src/coffeemachine.cc
    src/console.cc
    src/ConsoleInput.cc
    src/EspressoStrategy.cc
    src/FilteredCoffeeStrategy.cc
    src/MilkCoffeeStrategy.cc
    src/EspressoDippoStrategy.cc
)

target_include_directories(GameLib PUBLIC src)

add_executable(app src/main.cc)
target_link_libraries(app GameLib)


# 3. TEST CODE
enable_testing()

add_executable(run_tests tests/coffee_tests.cc)
target_link_libraries(run_tests GameLib gtest_main gmock_main)

include(GoogleTest)
gtest_discover_tests(run_tests)