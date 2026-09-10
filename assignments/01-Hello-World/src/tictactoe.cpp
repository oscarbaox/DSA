#include "tictactoe.hpp"

#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

// Constructor
TicTacToeBoard::TicTacToeBoard() {
    board_status = std::vector<char>(10, ' ');

    int initial_conditions[8][3] = {
        {1, 2, 3}, {4, 5, 6}, {7, 8, 9}, // Rows
        {1, 4, 7}, {2, 5, 8}, {3, 6, 9}, // Columns
        {1, 5, 9}, {3, 5, 7}             // Diagonals
    };

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 3; j++) {
            win_conditions[i][j] = initial_conditions[i][j];
        }
    }
}

// Determines whose turn it is
char TicTacToeBoard::next_move() const {
    int count_x = 0;
    int count_o = 0;

    for (int i = 1; i <= 9; i++) {
        if (board_status[i] == 'X') {
            count_x++;
        } else if (board_status[i] == 'O') {
            count_o++;
        }
    }

    if (count_x == count_o) {
        return 'X';
    }
    return 'O';
}

// Marks a square on the board
void TicTacToeBoard::mark(int row, int col) {
    int square_no = row * 3 + col + 1;

    if (board_status[square_no] != ' ') {
        throw std::invalid_argument("Square is already marked!");
    }

    char player = next_move();
    board_status[square_no] = player;
}

// Retrieves what is on a square ('X', 'O', or ' ')
char TicTacToeBoard::get_square(int row, int col) const {
    int square_no = row * 3 + col + 1;
    return board_status[square_no];
}

// Checks if the given player ('X' or 'O') has won
bool TicTacToeBoard::check_win(char player) const {
    for (int i = 0; i < 8; i++) {
        int sq1 = win_conditions[i][0];
        int sq2 = win_conditions[i][1];
        int sq3 = win_conditions[i][2];

        if (board_status[sq1] == player && board_status[sq2] == player &&
            board_status[sq3] == player) {
            return true;
        }
    }
    return false;
}

// Displays the board
void TicTacToeBoard::print_board() const {
    std::cout << "+-+-+-+\n";
    std::cout << "|" << board_status[1] << "|" << board_status[2] << "|" << board_status[3]
              << "|\n";
    std::cout << "+-+-+-+\n";
    std::cout << "|" << board_status[4] << "|" << board_status[5] << "|" << board_status[6]
              << "|\n";
    std::cout << "+-+-+-+\n";
    std::cout << "|" << board_status[7] << "|" << board_status[8] << "|" << board_status[9]
              << "|\n";
    std::cout << "+-+-+-+\n";
}