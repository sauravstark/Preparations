#include <iostream>
#include <string>

void func()
{
    //code
    std::string str1, str2;
    std::cin >> str1 >> str2;
    
    int len = str1.length();
    std::string rotated_l = str1.substr(2) + str1.substr(0, 2);
    std::string rotated_r = str1.substr(len - 2) + str1.substr(0, len - 2);
    if ((str2.compare(rotated_l) == 0) || (str2.compare(rotated_r) == 0))
        std::cout << 1 << std::endl;
    else
        std::cout << 0 << std::endl;
}

int main()
 {
	int T;
	std::cin >> T;
	
	for (int i = 0; i < T; ++i)
	    func();
	
	return 0;
}