#include<iostream>
#include<vector>
#include<algorithm>

bool reject(const std::vector<unsigned int> &valid_cols) {
    
    if (valid_cols.size() == 0)
        return false;
        
    unsigned int last = valid_cols.size() - 1;
    
    for(unsigned int i = 0; i < last; ++i) {
        unsigned int max_col = std::max(valid_cols[last],valid_cols[i]);
        unsigned int min_col = std::min(valid_cols[last],valid_cols[i]);
        unsigned int max_row = last;
        unsigned int min_row = i;
        if ((max_col - min_col == 0) || (max_col - min_col == max_row - min_row))
            return true;
    }
    
    return false;
}

bool accept(unsigned int N, const std::vector<unsigned int> &valid_cols) {
    return (valid_cols.size() == N);
}

void output(const std::vector<unsigned int> &valid_cols) {
    std::cout << "[";
    for (unsigned int col: valid_cols)
        std::cout << col << " ";
    std::cout << "] ";
}

bool bt(unsigned int N, std::vector<unsigned int> &valid_cols) {
    if (reject(valid_cols)) {
        return false;
    }
    
    if (accept(N, valid_cols)) {
        output(valid_cols);
        return true;
    }
    bool solved = false;
    unsigned int index = valid_cols.size();
    valid_cols.push_back(0);
    for (unsigned int i = 1; i <= N; ++i) {
        valid_cols[index] = i;
        if (bt(N, valid_cols))
            solved = true;
    }
    valid_cols.pop_back();
    return solved;
}

void func()
{
    //code
    unsigned int N;
    std::cin >> N;
    std::vector<unsigned int> valid_cols;
    if (!bt(N, valid_cols))
        std::cout << "-1";
    std::cout << std::endl;
}

int main()
 {
	int T;
	std::cin >> T;
	
	for (int i = 0; i < T; ++i)
	    func();
	
	return 0;
}