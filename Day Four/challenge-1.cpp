#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>

int main() {
	const std::vector<std::string> categories{"byr", "iyr", "eyr", "hgt", "hcl", "ecl", "pid", "cid"};
	std::string line;
	std::set<std::string> foundCategories;
	std::size_t validPassports {0};

	std::ifstream file ("input.in");
	if (file.is_open())
	{
		while ( getline (file,line) )
	    	{

			for(std::size_t i {0} ; i < categories.size() ; ++i)
			{
				if (line.find(categories.at(i)) != std::string::npos) foundCategories.insert(categories.at(i));
			}

			if(line.empty())
			{
				if(foundCategories.size() == 8) { validPassports++; }
				else if (foundCategories.size() == 7 && foundCategories.find("cid") == foundCategories.end()) { validPassports++; }
				foundCategories.clear();
				continue;
			}
    		}
    		file.close();
  	}
	
	std::cout << "Valid Passports: " << validPassports << std::endl;
  	return 0;
}
