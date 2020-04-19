#include <string>

int convertFive(int n)
{
//Your code here
    std::string num_string = std::to_string(n);
    std::size_t pos = num_string.find('0');
    while (pos != std::string::npos) {
        num_string.replace(pos, 1, "5");
        pos = num_string.find('0');
    }
    return std::stoi(num_string);
}