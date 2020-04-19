#include<iostream>
#include<algorithm>

bool overlaps(int x11, int x12, int x21, int x22) {
    int l1 = std::min(x11, x12),
        r1 = std::max(x11, x12),
        l2 = std::min(x21, x22),
        r2 = std::max(x21, x22);
        
    if ((l1 >= r2) || (r1 <= l2)) {
        //std::cout << "(" << l1 << ", " << r1 << ") and (" << l2 << ", " << r2 << ") don't overlap";
        return false;
    } else {
        //std::cout << "(" << l1 << ", " << r1 << ") and (" << l2 << ", " << r2 << ") overlap";
        return true;
    }
}

void func()
{
    int x11, y11, x12, y12, x21, y21, x22, y22;
    std::cin >> x11 >> y11 >> x12 >> y12 >> x21 >> y21 >> x22 >> y22;
    
    if (overlaps(x11, x12, x21, x22) && overlaps(y11, y12, y21, y22))
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