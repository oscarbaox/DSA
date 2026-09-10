#pragma once

#include <string>
#include <vector>

class TicTacToeBoard {
  private:
    int win_conditions[8][3];
    std::vector<char> board_status;

  public:
    TicTacToeBoard();

    char next_move() const;
    void mark(int row, int col);
    char get_square(int row, int col) const;
    bool check_win(char player) const;
    void print_board() const;
};