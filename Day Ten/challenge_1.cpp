#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

int main() {
	std::ifstream file ("input.in");
    std::string line;
	std::size_t oneJolt {0}, threeJolt {1};
	std::vector<int> joltages;

	if (file.is_open())
	{
		while ( getline (file,line) )
        {
			joltages.push_back(std::stoi(line));
        }
        file.close();
  	}
	std::sort(joltages.begin(), joltages.end());
	
	int prevElem {0};
	for (auto elem : joltages)
	{
		std:: cout << elem << " (diff: " << elem-prevElem << ")" << std::endl;
		switch(elem-prevElem)
		{
			case 1:
				++oneJolt;
				break;
			case 2:
				break;
			case 3:
				++threeJolt;
				break;
			default:
				std::cout << "something went wrong..." << elem-prevElem << std::endl;
				break;
		}

		prevElem = elem;
	}
	
	std::cout << "One jolts: " << oneJolt << " Three Jolts: " << threeJolt << " Result: " << oneJolt*threeJolt << std::endl;
	return 0;
}
