#include<iostream>
#include<vector>

void func()
{
    //code
    int N;
    std::cin >> N;
    long int sum = 0;
    
    std::vector<unsigned long int> arr(N, 0);
    for(int i = 0; i < N; ++i) {
        std::cin >> arr[i];
        sum += arr[i];
    }
    
    long int l_sum = 0, r_sum = sum;
    
    for(int i = 0; i < N; ++i) {
        r_sum -= arr[i];
        
        if (l_sum == r_sum) {
            std::cout << i + 1 << std::endl;
            return;
        } else {
            l_sum += arr[i];
        }
        
    }
    
    std::cout << -1 << std::endl;
    
}

int main()
 {
	int T;
	std::cin >> T;
	
	for (int i = 0; i < T; ++i)
	    func();
	
	return 0;
}