#include <iostream>
#include <algorithm>
#include <vector>
void func()
{
    //code
    int N;
    std::cin >> N;
    
    std::vector<int> primes({ 2, 3, 5, 7 });
    std::vector<int> factor_counts;
    
    int i = 0;
    
    int min_count = 0;
    for (int prime : primes) {
        int count = 0;
        while(N % prime == 0) {
            count++;
            N /= prime;
        }
        if (count == 1) {
            std::cout << "0" << std::endl;
            return;
        }
        if (count != 0) {
            factor_counts.push_back(count);
            if (min_count == 0 || count < min_count)
                min_count = count;
        }
    }
    
    if (N != 1) {
        std::cout << "0" << std::endl;
        return;
    }
    
    for (int count : factor_counts) {
        if (count % min_count != 0) {
            std::cout << "0" << std::endl;
            return;
        }
    }
    
    std::cout << "1" << std::endl;
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