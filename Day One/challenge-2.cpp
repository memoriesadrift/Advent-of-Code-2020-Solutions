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

	for(int i = 0 ; i < values.size() ; ++i)
	{
		for(int j = 0 ; j <  values.size() ; ++j){
			if(i == j) continue;
			if(occurences[2020-values.at(i)-values.at(j)] > 0)
			{
				std::cout << "The three elements that sum to 2020 are: "<< values.at(i) << " " << values.at(j) << " and " << 2020-values.at(i)-values.at(j) << std::endl;
				std::cout << "Their product is: " << values.at(i)*values.at(j)*(2020-values.at(i)-values.at(j)) << std::endl;
				return 0;
			}
		}
	}
	std::cout << "No solution found!" << std::endl;
  	return 0;
}
