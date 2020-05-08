#include <iostream>
#include <vector>
#include <algorithm>

#define iterator std::vector<int>::iterator

bool find_sum_pair(int sum, iterator str, iterator end) {
    end--;
    while (str != end) {
        if (*str + *end == sum)
            return true;
        else if (*str + *end < sum)
            str++;
        else
            end--;
    }
    return false;
}

void func()
{
    //code
    int N, X;
    std::cin >> N;
    
    std::vector<int> A(N);
    
    for (int i = 0; i < N; ++i) {
        std::cin >> A[i];
    }
    std::sort(A.begin(), A.end());
    
    std::cin >> X;
    
    for (auto itr1 = A.begin(); itr1 != A.end() - 3; ++itr1) {
        for (auto itr2 = itr1 + 1; itr2 != A.end() - 2; ++itr2) {
            if(find_sum_pair(X - *itr1 - *itr2, itr2 + 1, A.end())) {
                std::cout << "1" << std::endl;
                return;
            }
        }
    }
    std::cout << "0" << std::endl;
    return;
}

int main()
 {
	int T;
	std::cin >> T;
	
	for (int i = 0; i < T; ++i)
	    func();
	
	return 0;
}