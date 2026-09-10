cmake_minimum_required(VERSION 3.24)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(A01_hello_world)

include(CTest)
enable_testing()

if (MSVC)
    # warning level 4
    add_compile_options(/W4)
else()
    # additional warnings
    add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(PkgConfig REQUIRED)
pkg_check_modules(CRITERION REQUIRED criterion)

# library for tictactoe class
add_library(board_lib tictactoe.cpp)
target_include_directories(board_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(run_tests tictactoe_test.cpp tictactoe.cpp)
target_include_directories(run_tests PRIVATE ${CRITERION_INCLUDE_DIRS})
target_link_libraries(run_tests PRIVATE board_lib ${CRITERION_LIBRARIES})

add_test(NAME TicTacToeTests COMMAND run_tests)
 
add_executable(scheduler scheduler.cpp) 