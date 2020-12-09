#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
int main() {
	std::ifstream file ("input.in");
    std::string line;
    std::vector<int> seatIds;
	if (file.is_open())
	{
		while ( getline (file,line) )
        {
            int maxR {128};
            int minR {0};
            
            int maxS {8};
            int minS {0};

            int temp {0};
            
            for(auto c : line)
            {
                temp = (maxR-minR)/2;
                switch(c)
                {
                    case 'F':
                        maxR -= temp;
                        break;
                    case 'B':
                        minR += temp;
                        break;
                    case 'R':
                        temp = (maxS-minS)/2;
                        minS += temp;
                        break;
                    case 'L':
                        temp = (maxS-minS)/2;
                        maxS -= temp;
                        break;
                    default:
                        break;
                }
            }
            //std::cout << "MinR: " << minR << "MaxR: " << maxR << "MinS: " << minS << "MaxS: " << maxS  << std::endl;
            seatIds.push_back(minR * 8 + minS);
        }
        file.close();
  	}
    std::cout << "Min Seat: " << *std::min_element(seatIds.begin(), seatIds.end());
    std::cout << "Max Seat: " << *std::max_element(seatIds.begin(), seatIds.end());
    int currentSeatId {-1};

    std::sort(seatIds.begin(), seatIds.end());
    for(auto elem : seatIds)
    {
        if(currentSeatId == -1) { currentSeatId = elem; continue; }
        if(currentSeatId+1 != elem) std::cout << "Found your seat: " << currentSeatId+1 << std::endl;
        currentSeatId = elem;
    }
  	return 0;
}
