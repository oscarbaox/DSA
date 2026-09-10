add_library(board_lib tictactoe.cpp tictactoe.hpp)
target_include_directories(board_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_library(scheduler scheduler.cpp scheduler.hpp) 
target_include_directories(scheduler PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(scheduler_app scheduler_main.cpp)
target_link_libraries(scheduler_app PRIVATE scheduler)