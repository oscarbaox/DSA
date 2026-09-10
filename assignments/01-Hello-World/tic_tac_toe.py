"""
Class to generate a TicTacToe board and functions to play a full game.
"""


class TicTacToeBoard:
    """
    Represents a Tic-Tac-Toe board.

    This class manages the state of a Tic-Tac-Toe board, including marking
    squares, checking for wins, and displaying the current state of the board.

    Attributes:
    - win_conditions (list): A list of lists representing the winning
    combinations on the Tic-Tac-Toe board.
    - board_status (dict): A dictionary representing the current state of the
    board, with keys as square numbers (1 to 9) and values as "X", "O", or None.
    - current_move (str): Indicates the current move, either "X" or "O".
    """

    win_conditions = [
        [1, 2, 3],
        [4, 5, 6],
        [7, 8, 9],
        [1, 4, 7],
        [2, 5, 8],
        [3, 6, 9],
        [1, 5, 9],
        [3, 5, 7],
    ]

    def __init__(self):
        """
        Initializes a new Tic-Tac-Toe board.

        Initializes the board status with empty squares and sets the current
        move to "X".
        """
        self.board_status = dict.fromkeys(list(range(1, 10)))
        self.current_move = "X"

    def next_move(self):
        """
        Determines the next move on the board.

        Returns:
        - str: The player ("X" or "O") who is next to move.
        """
        moves = list(self.board_status.values())
        if moves.count("X") == moves.count("O"):
            return "X"
        return "O"

    def mark(self, row, col):
        """
        Marks a square on the board with the current player's symbol.

        Parameters:
        - row (int): The row index of the square (0 to 2).
        - col (int): The column index of the square (0 to 2).

        Raises:
        - ValueError: If the specified square is already marked.
        """
        square_no = row * 3 + col + 1
        if self.board_status[square_no] is not None:
            raise ValueError
        self.board_status[square_no] = self.next_move()

    def get_square(self, row, col):
        """
        Retrieves the symbol at the specified square on the board.

        Parameters:
        - row (int): The row index of the square (0 to 2).
        - col (int): The column index of the square (0 to 2).

        Returns:
        - str: The symbol at the specified square ("X", "O", or " " for empty).
        """
        square_no = row * 3 + col + 1
        if self.board_status[square_no] == "X":
            return "X"
        if self.board_status[square_no] == "O":
            return "O"
        return " "

    def check_win(self, player):
        """
        Checks if the specified player has won the game.

        Parameters:
        - player (str): The player ("X" or "O") to check for a win.

        Returns:
        - bool: True if the player has won, False otherwise.
        """
        for square_list in self.win_conditions:
            count = 0
            for square_no in square_list:
                if self.board_status[square_no] != player:
                    break
                count += 1

            if count == 3:
                return True

        return False

    def __repr__(self):
        """
        Returns a string representation of the Tic-Tac-Toe board.

        Returns:
        - str: The string representation of the board, formatted as a grid.
        """
        b = {
            key: value if value is not None else " "
            for key, value in self.board_status.items()
        }
        return (
            "+-+-+-+\n"
            f"|{b[1]}|{b[2]}|{b[3]}|\n"
            "+-+-+-+\n"
            f"|{b[4]}|{b[5]}|{b[6]}|\n"
            "+-+-+-+\n"
            f"|{b[7]}|{b[8]}|{b[9]}|\n"
            "+-+-+-+"
        )
