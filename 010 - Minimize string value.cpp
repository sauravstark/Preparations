#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

void func()
{
    //code
    std::string str;
    int k;
    
    std::cin >> str;
    std::cin >> k;
    
    std::vector<int> char_count(26, 0);
    
    for(char& c : str)
        ++char_count[c - 97];
    
    while(k--) {
        auto max_itr = std::max_element(char_count.begin(), char_count.end());
        
        if (*max_itr > 0)
            (*max_itr)--;
        else
            break;

    }
    
    auto aggregate = [](int a, int b) { return a + b * b; };
    
    std::cout << 
        std::accumulate(char_count.begin(), char_count.end(), 0, aggregate)
        << std::endl;
}

int main()
 {
	int T;
	std::cin >> T;

	for (int i = 0; i < T; ++i)
	    func();
	
	return 0;
}