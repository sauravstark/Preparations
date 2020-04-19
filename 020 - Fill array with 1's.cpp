#include<iostream>

void func()
{
    //code
    int N, x;
    std::cin >> N;
    
    int max_len = 0, cur_len = 0;
    
    for(int i = 0; i < N; ++i) {
        std::cin >> x;
        if (x == 0) {
            ++cur_len;
            if (i == N - 1)
                cur_len *= 2;
            if (cur_len > max_len)
                max_len = cur_len;
        } else {
            if (cur_len == i)
                cur_len *= 2;
            if (cur_len > max_len)
                max_len = cur_len;
            cur_len = 0;
        }
    }
    
    if (max_len == 2 * N)
        std::cout << -1 << std::endl;
    else
        std::cout << (max_len + 1) / 2 << std::endl;
}

int main()
 {
	int T;
	std::cin >> T;
	
	for (int i = 0; i < T; ++i)
	    func();
	
	return 0;
}