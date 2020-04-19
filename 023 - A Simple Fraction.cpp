#include<iostream>
#include<algorithm>
#include<vector>

unsigned int gcd(unsigned int a, unsigned int b) {
    unsigned int num1 = std::max(a, b);
    unsigned int num2 = std::min(a, b);
    
    if (num2 == 0) {
        return num1;
    } else if (num1 % num2 == 0) {
        return num2;
    } else {
        return gcd(num2, num1 % num2);
    }
}

void func()
{
    //code
    unsigned int N, D;
    std::cin >> N >> D;
    unsigned int hcf = gcd(N, D);
    N = N / hcf;
    D = D / hcf;
    
    std::vector<unsigned> after_decimal;
    unsigned int before_decimal = N / D;
    unsigned int dividend = N % D;
    if (dividend == 0) {
        std::cout << before_decimal << std::endl;
        return;
    }
    while(dividend != 0) {
        auto found = std::find(after_decimal.begin(), after_decimal.end(), dividend);
        if (found != after_decimal.end()) {
            std::cout << before_decimal << ".";
            for (auto itr = after_decimal.begin(); itr != found; ++itr) {
                std::cout << (*itr * 10) / D;
            }
                std::cout << "(";
            for (auto itr = found; itr != after_decimal.end(); ++itr) {
                std::cout << (*itr * 10) / D;
            }
                std::cout << ")" << std::endl;
                return;
        } else {
            after_decimal.push_back(dividend);
            dividend = (dividend * 10) % D;
        }
    }
    std::cout << before_decimal << ".";
    for (auto itr = after_decimal.begin(); itr != after_decimal.end(); ++itr) {
        std::cout << (*itr * 10) / D;
    }
    std::cout << std::endl;
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