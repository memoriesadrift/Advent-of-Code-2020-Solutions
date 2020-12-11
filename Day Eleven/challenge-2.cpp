#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

int countOccupiedSeats(std::vector<std::vector<char>> field, std::pair<int, int> pos)
{
	if(field.at(pos.second).at(pos.first) == '.') return -1; // Not a seat

	std::vector<std::pair<int, int>> directions = {{-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}};
	int count {0};

	for (auto elem : directions)
	{
		bool found {false};
		while(!found){
			if(pos.first + elem.first < 0 || pos.second + elem.second < 0 || pos.first + elem.first >= field.at(0).size() || pos.second + elem.second >= field.size()) break;
			if(field.at(pos.second + elem.second).at(pos.first + elem.first) == '#') found = true;
			else if (field.at(pos.second + elem.second).at(pos.first + elem.first) == 'L') break;
			else 
			{ 
				if(elem.first) elem.first += (elem.first / std::abs(elem.first));
				if(elem.second) elem.second += (elem.second / std::abs(elem.second));
			}
		}
		count += found ? 1 : 0;
	}

	return count;
}

int main() {
	std::ifstream file ("input.in");
    std::string line;
	std::vector<std::vector<char>> room;
	if (file.is_open())
	{
		while ( getline (file,line) )
        {
			std::vector<char> row;
			for(auto c : line)
			{
				row.push_back(c);
			}
			room.push_back(row);
        }
        file.close();
  	}
	
	int changes {1};
	while(changes)
	{
		std::vector<std::vector<char>> newRoom = room;
		changes = 0;
		for (int row {0}; row < room.size(); ++row )
		{
			for(int col {0}; col < room.at(row).size(); ++col)
			{
				if(room.at(row).at(col) == '.') continue;
				if(room.at(row).at(col) == 'L'  && countOccupiedSeats(room, {col, row}) == 0) { newRoom.at(row).at(col) = '#'; changes++; }
				else if(room.at(row).at(col) == '#' && countOccupiedSeats(room, {col, row}) >= 5) { newRoom.at(row).at(col) = 'L'; changes++; }
				else continue; 
			}
		}
		room = newRoom;
	}

	int count {0};
	for(auto row : room) 
	{
		for (auto ele : row)
		{
			if(ele == '#') count++;
		}
	}	

	std::cout << "Number of occupied seats: " << count << std::endl;
  	return 0;
}

