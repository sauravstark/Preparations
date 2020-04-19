#include<iostream>

void func()
{
    //code
    int A, B;
    std::cin >> A >> B;
    
    int diff = A ^ B;
    int count = 0;
    
    while (diff != 0) {
        if (diff & 1) {
            ++count;
        }
        diff = diff >> 1;
    }
    
    std::cout << count << std::endl;
    
}

int main()
 {
	int T;
	std::cin >> T;
	
	for (int i = 0; i < T; ++i)
	    func();
	
	return 0;
}