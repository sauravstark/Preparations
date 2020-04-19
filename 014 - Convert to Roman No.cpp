#include<iostream>
#include<string>

std::string digitToRoman(int n, std::string one, std::string five, std::string ten) {
    switch (n) {
        case 1:
            return one;
        case 2:
            return one + one;
        case 3:
            return one + one + one;
        case 4:
            return one + five;
        case 5:
            return five;
        case 6:
            return five + one;
        case 7:
            return five + one + one;
        case 8:
            return five + one + one + one;
        case 9:
            return one + ten;
        default:
            return "";
    }
}

// n :given number that you are require to convert
void convertToRoman(int n) 
{
//Your code here
    std::string one, five, ten;
    
    int ones = n % 10;
    n /= 10;
    int tens = n % 10;
    n /= 10;
    int hundreds = n % 10;
    n /= 10;
    int thousands = n % 10;
    
    std::cout << digitToRoman(thousands, "M", "V", "X") + 
        digitToRoman(hundreds, "C", "D", "M") + 
        digitToRoman(tens, "X", "L", "C") + 
        digitToRoman(ones, "I", "V", "X");
}