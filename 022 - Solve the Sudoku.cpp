#include<iostream>

bool not_safe(bool *present, int val) {
	if (val == 0)
		return false;

	if (present[val - 1])
		return true;

	present[val - 1] = true;
	return false;
}

bool reject(int *sudoku_board) {
	for (int row = 0; row < 9; ++row) {
		bool present[9] = { false };
		for (int col = 0; col < 9; ++col) {

			int index = row * 9 + col;
			int val = sudoku_board[index];
			
			if (not_safe(present, val)) {
				return true;
			}
		}
	}

	for (int col = 0; col < 9; ++col) {
		bool present[9] = { false };
		for (int row = 0; row < 9; ++row) {

			int index = row * 9 + col;
			int val = sudoku_board[index];

			if (not_safe(present, val)) {
				return true;
			}
		}
	}

	for (int block = 0; block < 9; ++block) {
		bool present[9] = { false };
		for (int box = 0; box < 9; ++box) {
			int row = (block / 3) * 3 + box / 3;
			int col = (block % 3) * 3 + box % 3;

			int index = row * 9 + col;
			int val = sudoku_board[index];

			if (not_safe(present, val)) {
				return true;
			}
		}
	}

	return false;
}

bool accept(int *sudoku_board) {
	for (int i = 0; i < 81; ++i) {
		if (sudoku_board[i] == 0)
			return false;
	}

	return !reject(sudoku_board);
}

void output(int *sudoku_board) {
	for (int row = 0; row < 9; ++row) {
		for (int col = 0; col < 9; ++col) {
			std::cout << sudoku_board[row * 9 + col] << " ";
		}
	}
	std::cout << std::endl;
}

bool solve(int *sudoku_board, bool *fixed_pos, int index = 0) {

	if (reject(sudoku_board)) {
		return false;
	}

	if (accept(sudoku_board)) {
		output(sudoku_board);
		return true;
	}
	
	if (fixed_pos[index])
		return solve(sudoku_board, fixed_pos, index + 1);

	for (int i = 1; i <= 9; ++i) {
		sudoku_board[index] = i;
		if (!reject(sudoku_board) && (solve(sudoku_board, fixed_pos, index + 1)))
			return true;
	}
	sudoku_board[index] = 0;
	return false;
}

void func()
{
    //code
    int sudoku_board[81];
    bool fixed_pos[81];
    
    for (int i = 0; i < 81; ++i) {
        std::cin >> sudoku_board[i];
        fixed_pos[i] = !(sudoku_board[i] == 0);
    }
    
    solve(sudoku_board, fixed_pos);
}

int main()
 {
	int T;
	std::cin >> T;
	
	for (int i = 0; i < T; ++i)
	    func();
	
	return 0;
}