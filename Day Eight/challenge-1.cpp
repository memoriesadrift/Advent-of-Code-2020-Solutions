#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

int main() {
	std::ifstream file ("input.in");
    std::string line;
    std::vector<std::pair<std::string, int>> instructions;
	
	if (file.is_open())
	{
		while ( getline (file,line) )
        {
			std::string opName {line.substr(0,3)};
			line = line.substr(4);
			int opArg {std::stoi(line)};
			//std::cout << opName << " " << opArg << std::endl;

			instructions.push_back(std::make_pair(opName, opArg));
        }
        file.close();
  	}
  	std::vector<bool> visited(instructions.size(), 0);

	int acc {0};
	for(int idx {0} ; idx < instructions.size() ; ++idx)
	{
		if(visited.at(idx)) { std::cout << "Loop found! Acc: " << acc << std::endl; break; }
		auto cmd {instructions.at(idx)};
		//std::cout << "Executing " << cmd.first << " with param: " << cmd.second << " and acc: " << acc << std::endl;
		if(cmd.first == "nop") {visited.at(idx) = true; continue; }
		if(cmd.first == "acc") {visited.at(idx) = true; acc+= cmd.second;}
		if(cmd.first == "jmp") {visited.at(idx) = true; idx += cmd.second-1; }
	}
	return 0;
}
