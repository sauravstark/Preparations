#include<iostream>

void func()
{
    //code
    unsigned long long int N;
    std::cin >> N;
    
    unsigned long long int possibilities = 1;
    for (int i = 0; i < N; ++i) {
        possibilities *= 10;
    }
    
    unsigned long long int x = 1;
    
    for (int i = 0; i <= N; ++i) {
        possibilities -= x;
        x *= 9;
    }
    
    std::cout << possibilities << std::endl;
    
}

int main()
 {
	int T;
	std::cin >> T;
	
	for (int i = 0; i < T; ++i)
	    func();
	
	return 0;
}