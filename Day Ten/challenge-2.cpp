#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

long long permutations(int n)
{
	if (n == 0) return 1;
	if (n < 3) return n;
	if (n == 3) return 4;
	if (n == 4) return 7;
	if (n == 5) return 14;
	
	std::cout << "Uncomputed for: " << n << std::endl;
	return 0;
}

int main() {
	std::ifstream file ("input.in");
    std::string line;
	std::vector<int> joltages, differences;

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
		//std::cout << " diff: " << elem-prevElem << "elem: " << elem <<  std::endl;
		differences.push_back(elem-prevElem);
		prevElem = elem;
	}
	
	long long combinations {1};
	std::size_t segment {0};
	for (auto elem : differences)
	{
		if(elem == 1) segment += elem;
		else
		{
			std::cout << "calculating combinations for: " << segment << std::endl;
			combinations *= permutations(segment);
			segment = 0;
		}
	}
	std::cout << "calculating combinations for: " << segment << std::endl;
	combinations *= permutations(segment);
	segment = 0;
	
	std::cout << "Combinations: " << combinations << std::endl;

	return 0;
}
