#include<iostream>
#include<algorithm>

void func()
{
    //code
    
    int N;
    std::cin >> N;
    int count = 0;
    
    for (int i = 0; i < 10; ++i) {
        int pos = 2 << i;
        count += ((N + 1) / pos) * (pos / 2);
        count += std::max(((N + 1) % pos) - pos / 2, 0);
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