#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

void set_var(int& var, int i)
{
	var += i;
	if(var == 360 ) var = 0;
	while(var > 360) {var -= 360;}
	while(var < 0) {var += 360;}
}

int main() {
	std::ifstream file ("input.in");
    std::string line;
	std::vector<std::pair<char, int>> values;
	int facing {90}; // 0 - N, 90 - E, 180 - S, 270 - W
	std::vector<int>distances (2, 0); // NS/WE N+, S- ; W+, E-
	
	if (file.is_open())
	{
		while ( getline (file,line) )
        {
			values.push_back({line.front(), std::stoi(line.substr(1))});
        }
        file.close();
  	}

	for(auto elem : values)
	{
		switch (elem.first)
		{
		case 'N':
			distances.at(0) += elem.second;	
			break;
		case 'S':
			distances.at(0) -= elem.second;	
			break;
		case 'W':
			distances.at(1) += elem.second;	
			break;
		case 'E':
			distances.at(1) -= elem.second;	
			break;
		case 'R':
			set_var(facing, elem.second);
			break;
		case 'L':
			set_var(facing, elem.second * -1);
			break;
		case 'F':
			switch(facing/90)
			{
			case 0:
				distances.at(0) += elem.second;	
				break;
			case 1:
				distances.at(1) -= elem.second;	
				break;
			case 2:
				distances.at(0) -= elem.second;	
				break;
			case 3:
				distances.at(1) += elem.second;	
				break;
			}
			break;
		
		default:
			break;
		}
	}

	std::cout << "Manhattan Distance: " << std::abs(distances.at(1)) + std::abs(distances.at(0)) << std::endl;
	
  	return 0;
}
