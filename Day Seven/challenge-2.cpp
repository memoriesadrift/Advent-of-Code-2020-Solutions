#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

bool vectorContains(std::vector<std::string> v, std::string s)
{
	for(auto v_s : v)
	{
		if(v_s == s) return true;
	}
	return false;
}

int findInMap(std::map<std::string, std::vector<std::pair<int, std::string>>>& map, std::string key)
{
	if(map.at(key).empty()) return 1;
	
	int count {1};
	for(auto e : map.at(key))
	{
		//std::cout << e.first << "x" << e.second << "\n";
		count += e.first * findInMap(map, e.second);
	}
	return count;
}

int main() {
	std::ifstream file ("input.in");
    std::string line;

	std::map<std::string, std::vector<std::pair<int, std::string>>> map;
	if (file.is_open())
	{
		while ( getline (file,line) )
        {
			// build map
			std::string key {line.substr(0, line.find(" contain ")-1)};
			std::vector<std::pair<int, std::string>> values {};
			line = line.substr(line.find(" contain ")+9);
			
			if(line.find("no other bags") != std::string::npos)
			{
				map.insert(std::make_pair(key, values));
				continue;
			}

			while(line.find(", ") != std::string::npos)
			{
				int num {stoi(line.substr(0,1))};
				auto temp = line.substr(2, line.find(", ")-2);
				if(temp.back() == 's') temp.erase(temp.end()-1);

				//std:: cout << "#:" <<  num << "#" << temp << "#\n";

				values.push_back( std::make_pair(num, temp));
				line = line.substr(line.find(", ")+2);
			}

			int num {stoi(line.substr(0,1))};
			line = line.substr(2);
			if(line.back() == '.') line.erase(line.end()-1);
			if(line.back() == 's') line.erase(line.end()-1);

			//std:: cout << "#:" << num << "#" << line << "#\n";

			values.push_back( std::make_pair(num, line));

			map.insert(std::make_pair(key, values));
        }
		
		std::cout << "Final count: " << findInMap(map, "shiny gold bag")-1 << std::endl;

        file.close();
  	}
  	return 0;
}
