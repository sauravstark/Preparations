#include<iostream>
#include<string>

void backtrack(std::string prefix, std::string input) {
    if (input == "") {
        std::cout << "(" << prefix << ")";
        return;
    } else {
        backtrack(prefix + " " + input[0], input.substr(1));
        backtrack(prefix + input[0], input.substr(1));
    }
}

void func()
{
    //code
    std::string S;
    std::cin >> S;
    std::string prefix = S.substr(0, 1);
    std::string input = S.substr(1);
    backtrack(prefix, input);
    std::cout << std::endl;
}

int main()
 {
	int T;
	std::cin >> T;
	
	for (int i = 0; i < T; ++i)
	    func();
	
	return 0;
}