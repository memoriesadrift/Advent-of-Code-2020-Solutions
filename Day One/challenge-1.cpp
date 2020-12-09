#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

int main() {
	std::string line;
	std::map<int, int> occurences;
	std::vector<int> values;
	std::ifstream file ("input-first-challenge.in");
	if (file.is_open())
	{
		while ( getline (file,line) )
	    	{
			values.push_back(std::stoi(line));
			occurences[values.back()]++;
    		}
    		file.close();
  	}

	for(auto& elem : values)
	{
		if(occurences[2020-elem] > 0)
		{
			std::cout << "The two elements that sum to 2020 are: "<< elem << " " << 2020-elem << std::endl;
			std::cout << "Their product is: " << elem * (2020-elem) << std::endl;
			break;
		}
	}

  	return 0;
}
