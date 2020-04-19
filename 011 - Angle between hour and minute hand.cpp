#include<iostream>
#include<cmath>

void func()
{
    //code
    float hh, mm;
    std::cin >> hh >> mm;
    
    hh = (hh == 12 ? 0 : hh);
    mm = (mm == 60 ? 0 : mm);
    
    float mm_pos = mm * (360 / 60);
    float hh_pos = (hh + float(mm) / 60) * (360 / 12);
    
    float angle_diff = std::abs(hh_pos - mm_pos);
    
    int result = int(std::min(angle_diff, 360 - angle_diff));
    
    std::cout << result << std::endl;
}

int main()
 {
	int T;
	std::cin >> T;
	
	for (int i = 0; i < T; ++i)
	    func();
	
	return 0;
}