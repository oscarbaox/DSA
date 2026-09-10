#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>

#include "tictactoe.hpp"

// Type aliases for move coordinates and game definitions
using Move = std::pair<int, int>;

struct GameMoves {
    std::vector<Move> moves;
    char expected_winner;
};

struct GameRepr {
    std::vector<Move> moves;
    std::string expected_repr;
};

static const std::vector<GameMoves> board_moves = {
    // Horizontal wins
    {{{0, 0}, {2, 0}, {0, 1}, {1, 1}, {0, 2}}, 'X'},
    {{{0, 0}, {1, 0}, {2, 1}, {1, 1}, {0, 2}, {1, 2}}, 'O'},
    {{{2, 0}, {0, 0}, {2, 1}, {1, 1}, {2, 2}}, 'X'},
    // Vertical wins
    {{{0, 2}, {0, 0}, {1, 1}, {2, 0}, {2, 2}, {1, 0}}, 'O'},
    {{{0, 1}, {0, 0}, {1, 1}, {1, 2}, {2, 1}}, 'X'},
    {{{0, 0}, {0, 2}, {2, 0}, {1, 2}, {1, 1}, {2, 2}}, 'O'},
    // Diagonal wins
    {{{0, 0}, {0, 2}, {1, 1}, {1, 2}, {2, 2}}, 'X'},
    {{{0, 0}, {2, 0}, {1, 0}, {1, 1}, {2, 2}, {0, 2}}, 'O'},
    // Draw
    {{{0, 0}, {1, 1}, {2, 2}, {0, 1}, {2, 1}, {2, 0}, {0, 2}, {1, 2}, {1, 0}}, '\0'}};

static const std::vector<GameRepr> board_reprs = {
    {{{0, 0}, {2, 0}, {0, 1}, {1, 1}, {0, 2}},
     "+-+-+-+\n"
     "|X|X|X|\n"
     "+-+-+-+\n"
     "| |O| |\n"
     "+-+-+-+\n"
     "|O| | |\n"
     "+-+-+-+"},
    {{{0, 0}, {1, 0}, {2, 1}, {1, 1}, {0, 2}, {1, 2}},
     "+-+-+-+\n"
     "|X| |X|\n"
     "+-+-+-+\n"
     "|O|O|O|\n"
     "+-+-+-+\n"
     "| |X| |\n"
     "+-+-+-+"},
    {{{2, 0}, {0, 0}, {2, 1}, {1, 1}, {2, 2}},
     "+-+-+-+\n"
     "|O| | |\n"
     "+-+-+-+\n"
     "| |O| |\n"
     "+-+-+-+\n"
     "|X|X|X|\n"
     "+-+-+-+"},
    {{{0, 2}, {0, 0}, {1, 1}, {2, 0}, {2, 2}, {1, 0}},
     "+-+-+-+\n"
     "|O| |X|\n"
     "+-+-+-+\n"
     "|O|X| |\n"
     "+-+-+-+\n"
     "|O| |X|\n"
     "+-+-+-+"},
    {{{0, 1}, {0, 0}, {1, 1}, {1, 2}, {2, 1}},
     "+-+-+-+\n"
     "|O|X| |\n"
     "+-+-+-+\n"
     "| |X|O|\n"
     "+-+-+-+\n"
     "| |X| |\n"
     "+-+-+-+"},
    {{{0, 0}, {0, 2}, {2, 0}, {1, 2}, {1, 1}, {2, 2}},
     "+-+-+-+\n"
     "|X| |O|\n"
     "+-+-+-+\n"
     "| |X|O|\n"
     "+-+-+-+\n"
     "|X| |O|\n"
     "+-+-+-+"},
    {{{0, 0}, {0, 2}, {1, 1}, {1, 2}, {2, 2}},
     "+-+-+-+\n"
     "|X| |O|\n"
     "+-+-+-+\n"
     "| |X|O|\n"
     "+-+-+-+\n"
     "| | |X|\n"
     "+-+-+-+"},
    {{{0, 0}, {2, 0}, {1, 0}, {1, 1}, {2, 2}, {0, 2}},
     "+-+-+-+\n"
     "|X| |O|\n"
     "+-+-+-+\n"
     "|X|O| |\n"
     "+-+-+-+\n"
     "|O| |X|\n"
     "+-+-+-+"},
    {{{0, 0}, {1, 1}, {2, 2}, {0, 1}, {2, 1}, {2, 0}, {0, 2}, {1, 2}, {1, 0}},
     "+-+-+-+\n"
     "|X|O|X|\n"
     "+-+-+-+\n"
     "|X|O|O|\n"
     "+-+-+-+\n"
     "|O|X|X|\n"
     "+-+-+-+"}};

// Unit Tests

// 1. test_first_move
Test(tic_tac_toe_suite, test_first_move) {
    TicTacToeBoard board;
    cr_assert_eq(board.next_move(), 'X', "The first move must be 'X'.");
}

// 2. test_next_move (iterates through game sequences and verifies alternating turns)
Test(tic_tac_toe_suite, test_next_move) {
    const char players[2] = {'X', 'O'};

    for (const GameMoves &game : board_moves) {
        TicTacToeBoard board;
        for (size_t i = 0; i < game.moves.size(); ++i) {
            char expected_player = players[i % 2];
            cr_assert_eq(board.next_move(), expected_player, "Expected player %c at move index %zu",
                         expected_player, i);
            board.mark(game.moves[i].first, game.moves[i].second);
        }
    }
}

// 3. test_mark_empty (verifies all 9 squares can be marked without exception)
Test(tic_tac_toe_suite, test_mark_empty) {
    for (int row = 0; row < 3; ++row) {
        for (int col = 0; col < 3; ++col) {
            TicTacToeBoard board;
            board.mark(row, col);
            cr_assert(true);
        }
    }
}