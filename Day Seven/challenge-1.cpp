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

bool findInMap(std::map<std::string, std::vector<std::string>> map, std::string key, std::string value)
{
	//if(key == value) return true;
	if(vectorContains(map[key], value)) { std::cout << "found!\n"; return true; }
	//std::cout << "couldn't find value #" << value << "# in #" << key << "#" << std::endl;
	for(auto e : map[key])
	{
		if (findInMap(map, e, value)) return true;
	}

	return false;
}

int main() {
	std::ifstream file ("input.in");
    std::string line;
	int count {0};
	std::map<std::string, std::vector<std::string>> map;
	map.insert(std::make_pair("no other bags", std::vector<std::string> {}));
	if (file.is_open())
	{
		while ( getline (file,line) )
        {
			// build map
			std::string key {line.substr(0, line.find(" bag"))};
			std::vector<std::string> values {};
			line = line.substr(line.find("contain")+8);

			if(line.find("no other bags") != std::string::npos)
			{
				//values.push_back("no other bags");
				//std::cout << "Pushed back: " << values.back() << std::endl;
				continue;
			}

			line = line.substr(2);
			//std::cout << line << std::endl;

			while(line.find(",") != std::string::npos)
			{
				if(line.front() == ' ') line.substr(1);
				values.push_back(line.substr(0, line.find(" bag")));
				//std::cout << "Pushed back: " << values.back() << std::endl;
				line = line.substr(line.find(",")+4);
				//std::cout << "Line shrunk to: " << line << std::endl; 
			}
			line = line.substr(0, line.find(" bag"));
			if(line.front() == ' ') line = line.substr(1);
			values.push_back(line);
			//std::cout << "Pushed back: " << values.back() << std::endl;
			map.insert(std::make_pair(key, values));
        }
		
		for(auto elem : map)
		{
			//std::cout << "###CASE:" << elem.first << "###" << std::endl; 
			count += (int)findInMap(map, elem.first, "shiny gold");
		}
		std::cout << "Final count: " << count << std::endl;

        file.close();
  	}
  	return 0;
}
