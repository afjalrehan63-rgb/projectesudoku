#include <iostream>
#include <vector>

using Board = std::vector<std::vector<int>>;

bool canPlace(const Board& board, int row, int col, int value) {
	for (int i = 0; i < 9; ++i) {
		if (board[row][i] == value || board[i][col] == value)
			return false;
	}

	const int boxRow = (row / 3) * 3;
	const int boxCol = (col / 3) * 3;
	for (int r = boxRow; r < boxRow + 3; ++r) {
		for (int c = boxCol; c < boxCol + 3; ++c) {
			if (board[r][c] == value)
				return false;
		}
	}
	return true;
}

bool solve(Board& board) {
	for (int row = 0; row < 9; ++row) {
		for (int col = 0; col < 9; ++col) {
			if (board[row][col] != 0)
				continue;

			for (int value = 1; value <= 9; ++value) {
				if (canPlace(board, row, col, value)) {
					board[row][col] = value;
					if (solve(board))
						return true;
					board[row][col] = 0;
				}
			}
			return false;
		}
	}
	return true;
}

int main() {
	Board board(9, std::vector<int>(9));
	// Read 81 numbers; use 0 for empty cells.
	for (auto& row : board) {
		for (int& cell : row) {
			if (!(std::cin >> cell) || cell < 0 || cell > 9) {
				std::cerr << "Enter exactly 81 integers from 0 to 9.\n";
				return 1;
			}
		}
	}

	// Reject inconsistent starting clues.
	for (int row = 0; row < 9; ++row) {
		for (int col = 0; col < 9; ++col) {
			const int value = board[row][col];
			if (value == 0)
				continue;
			board[row][col] = 0;
			const bool valid = canPlace(board, row, col, value);
			board[row][col] = value;
			if (!valid) {
				std::cout << "No solution\n";
				return 0;
			}
		}
	}

	if (!solve(board)) {
		std::cout << "No solution\n";
		return 0;
	}

	for (const auto& row : board) {
		for (int col = 0; col < 9; ++col)
			std::cout << row[col] << (col == 8 ? '\n' : ' ');
	}
	return 0;
}
