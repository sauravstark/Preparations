#include<iostream>

void func()
{
    //code
    int N;
    std::cin >> N;
    
    unsigned long long int mod[3] = { 0 };
    int x;
    
    for (int i = 0; i < N; ++i) {
        std::cin >> x;
        
        mod[x % 3]++;
    }
    
    unsigned long long int possibilities = 0;
    
    // ways of selecting two nums with mod 0
    possibilities += mod[0] * (mod[0] - 1) / 2;
    // ways of selecting one num with mod 1 & one with mod 2
    possibilities += mod[1] * mod[2];
    
    // ways of selecting three nums with mod 0
    possibilities += mod[0] * (mod[0] - 1) * (mod[0] - 2) / 6;
    // ways of selecting three nums with mod 1
    possibilities += mod[1] * (mod[1] - 1) * (mod[1] - 2) / 6;
    // ways of selecting three nums with mod 2
    possibilities += mod[2] * (mod[2] - 1) * (mod[2] - 2) / 6;
    // ways of selecting one num with mod 0, one with mod 1 & one with mod 2
    possibilities += mod[0] * mod[1] * mod[2];
    
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