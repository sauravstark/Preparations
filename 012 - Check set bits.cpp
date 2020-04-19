#include<iostream>
#include<cmath>

void func()
{
    //code
    int N;
    std::cin >> N;
    N++;
    
    float log_val = log2(N);
    if (int(log_val) == log_val)
        std::cout << "YES" << std::endl;
    else
        std::cout << "NO" << std::endl;
    
}

int main()
 {
	int T;
	std::cin >> T;
	
	for (int i = 0; i < T; ++i)
	    func();
	
	return 0;
}