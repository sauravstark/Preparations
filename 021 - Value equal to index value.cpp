#include<iostream>

void func()
{
    //code
    int N;
    std::cin >> N;
    
    int x;
    bool found = false;
    
    for (int i = 1; i <= N; ++i) {
        std::cin >> x;
        if (x == i) {
            found = true;
            std::cout << i << " ";
        }
    }
    
    if (found)
        std::cout << std::endl;
    else
        std::cout << "Not Found" << std::endl;
}

int main()
 {
	int T;
	std::cin >> T;
	
	for (int i = 0; i < T; ++i)
	    func();
	
	return 0;
}