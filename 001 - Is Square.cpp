#include <iostream>
#include <vector>
#include <algorithm>

void func()
{
    int x1, x2, x3, x4, y1, y2, y3, y4;
    std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
    
    std::vector<int> dist;
    
    dist.push_back((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
    dist.push_back((x3 - x2) * (x3 - x2) + (y3 - y2) * (y3 - y2));
    dist.push_back((x4 - x3) * (x4 - x3) + (y4 - y3) * (y4 - y3));
    dist.push_back((x1 - x4) * (x1 - x4) + (y1 - y4) * (y1 - y4));
    dist.push_back((x3 - x1) * (x3 - x1) + (y3 - y1) * (y3 - y1));
    dist.push_back((x4 - x2) * (x4 - x2) + (y4 - y2) * (y4 - y2));
    
    std::sort(dist.begin(), dist.end());
    
    if ((dist[0] == dist[3]) && (dist[4] == dist[5]) && (dist[0] != 0))
        std::cout << "Yes" << std::endl;
    else
        std::cout << "No" << std::endl;
}

int main()
 {
	//code
	int T;
	std::cin >> T;
	for (int i = 0; i < T; ++i)
	{
	    func();
	}
	return 0;
}