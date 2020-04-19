#include<iostream>
#include<set>

void func()
{
    //code
    long long unsigned int N, P;
    std::cin >> N >> P;
    long long unsigned int num;
    std::set<long long unsigned int> factors;
    bool found = false;
    
    for (int i = 0; i < N; ++i) {
        std::cin >> num;
        if (!found) {
            if (num == 0)
                continue;
            if (P % num == 0) {
                if (factors.find(P / num) != factors.end())
                    found = true;
                else
                    factors.insert(num);
            }
        }
    }
    
    if (found)
        std::cout << "Yes" << std::endl;
    else
        std::cout << "No" << std::endl;
        
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