#include<iostream>

void func()
{
    //code
    
    int num_rows, num_cols;
    std::cin >> num_rows >> num_cols;
    
    bool ones_row[num_rows] = { false };
    bool ones_col[num_cols] = { false };
    bool mat[num_rows][num_cols];
    
    int x;
    
    for (int r = 0; r < num_rows; ++r) {
        for (int c = 0; c < num_cols; ++c) {
            std::cin >> x;
            if (x == 1) {
                mat[r][c] = true;
                ones_row[r] = true;
                ones_col[c] = true;
            } else {
                mat[r][c] = false;
            }
        }
    }
    
    for (int r = 0; r < num_rows; ++r) {
        for (int c = 0; c < num_cols; ++c) {
            if (mat[r][c] || ones_row[r] || ones_col[c])
                std::cout << "1 ";
            else
                std::cout << "0 ";
        }
        std::cout << std::endl;
    }
}

int main()
 {
	int T;
	std::cin >> T;
	
	for (int i = 0; i < T; ++i)
	    func();
	
	return 0;
}