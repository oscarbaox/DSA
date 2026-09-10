add_executable(run_tests tictactoe_test.cpp)
target_include_directories(run_tests PRIVATE ${CRITERION_INCLUDE_DIRS})
target_link_libraries(run_tests PRIVATE board_lib ${CRITERION_LIBRARIES})

add_test(NAME TicTacToeTests COMMAND run_tests)

add_executable(scheduler_tests scheduler_test.cpp)
target_include_directories(scheduler_tests PRIVATE ${CRITERION_INCLUDE_DIRS})
target_link_libraries(scheduler_tests PRIVATE scheduler ${CRITERION_LIBRARIES})

add_test(NAME SchedulerTests COMMAND scheduler_tests)
 
