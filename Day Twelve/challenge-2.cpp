#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

void rotate_wp(std::vector<int>& wp, int i)
{
	// R90
	// N(0) -> E(-1) -> S(-0) -> W(1)
	// L90
	// W(1) -> S(-0) -> E(-1) -> N(0)

	// R rotation
	if (i > 0){
		while(i)
		{
			int temp = wp.at(0);
			wp.at(0) = wp.at(1);
			if(temp == 0) { wp.at(1) = temp; }
			else { wp.at(1) = -1 * temp; }
			i-= 90;
		}
	} else 
	{
		i = i * -1;
		while(i)
		{
			int temp = wp.at(1);
			wp.at(1) = wp.at(0);
			if(temp == 0) { wp.at(0) = temp; }
			else { wp.at(0) = -1 * temp; }
			i-= 90;
		}
	}

}

int main() {
	std::ifstream file ("input.in");
    std::string line;
	std::vector<std::pair<char, int>> values;
	std::vector<int>waypoint {1, -10};
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
			waypoint.at(0) += elem.second;	
			break;
		case 'S':
			waypoint.at(0) -= elem.second;	
			break;
		case 'W':
			waypoint.at(1) += elem.second;	
			break;
		case 'E':
			waypoint.at(1) -= elem.second;	
			break;
		case 'R':
			rotate_wp(waypoint, elem.second);
			break;
		case 'L':
			rotate_wp(waypoint, elem.second * -1);
			break;
		case 'F':
			distances.at(0) += elem.second * waypoint.at(0);
			distances.at(1) += elem.second * waypoint.at(1);
			break;
		
		default:
			break;
		}
	}

	std::cout << "Manhattan Distance: " << std::abs(distances.at(1)) + std::abs(distances.at(0)) << std::endl;
	
  	return 0;
}
