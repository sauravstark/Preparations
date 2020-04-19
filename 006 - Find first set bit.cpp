#include<iostream>
#include<cmath>

void func()
{
    //code
    long int N;
    std::cin >> N;
    int pos = (N) & (~N + 1);
    if (pos == 0) {
        std::cout << "0" << std::endl;
    } else {
        std::cout << int(log2(pos)) + 1 << std::endl;
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