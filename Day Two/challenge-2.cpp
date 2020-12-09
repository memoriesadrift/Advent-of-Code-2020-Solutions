#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <tuple>

std::tuple<int, int, char, std::string> parse_input(std::string input)
{
	int firstPos = {0};
	int secondPos = {0};
	char c;
	std::string pw;

	std::string::size_type dashPos = input.find('-');
	std::string::size_type spacePos = input.find(' ');
	std::string::size_type colonPos = input.find(':');

	firstPos = std::stoi(input.substr(0, dashPos));
	secondPos = std::stoi(input.substr(dashPos+1, spacePos));
	c = input.at(spacePos+1);
	pw = input.substr(colonPos+2, input.size());

	return std::make_tuple(firstPos, secondPos, c, pw);
}

bool validate_password(std::tuple<int, int, char, std::string> input)
{
	std::string pw { std::get<3>(input) };
	return ((pw.at(std::get<0>(input) - 1) == std::get<2>(input)) + (pw.at(std::get<1>(input) - 1) == std::get<2>(input)) == 1); 
}

int main() {
	std::string line;
	std::size_t count {0};
	std::vector<std::tuple<int, int, char, std::string>> values;
	std::ifstream file ("input.in");
	if (file.is_open())
	{
		while ( getline (file,line) )
	    	{
			values.push_back(parse_input(line));
    		}
    		file.close();
  	}

	for(auto& elem : values)
	{
		count += validate_password(elem);		
	}

	std::cout << "Valid passwords: " << count << "." << std::endl; 

  	return 0;
}
