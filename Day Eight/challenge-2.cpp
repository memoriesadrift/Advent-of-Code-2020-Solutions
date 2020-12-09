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
  	std::vector<bool> visitedWhileChecking(instructions.size(), 0);
  	std::vector<bool> checkedAgain(instructions.size(), 0);
	bool checking;
	std::pair<std::string, int> testedCommand;

	int acc {0};
	for(int idx {0} ; idx < instructions.size() ; ++idx)
	{
		auto cmd {instructions.at(idx)};
		//std::cout << "Executing " << cmd.first << " with param: " << cmd.second << " and acc: " << acc << std::endl;
		if(cmd.first == "nop") 
		{
			if(visited.at(idx) && !checking && !checkedAgain.at(idx))
			{
				checking = true;
				checkedAgain.at(idx) = true;
				testedCommand = cmd;
				idx+= cmd.second;
				visitedWhileChecking.at(idx) = true;
			}

			if(checking)
			{
				if (visitedWhileChecking.at(idx))
				{
					checking = false;
					visitedWhileChecking = std::vector<bool>(instructions.size(), 0);
					idx = -1;
					acc = 0;
					continue;
				} else
				{
					visitedWhileChecking.at(idx) = true;
				}
			}
			
			visited.at(idx) = true;
			continue;
		}
		if(cmd.first == "acc") { visited.at(idx) = true; acc+= cmd.second;}
		if(cmd.first == "jmp") 
		{
			if(visited.at(idx) && !checking && !checkedAgain.at(idx))
			{
				checking = true;
				checkedAgain.at(idx) = true;
				testedCommand = cmd;
				visitedWhileChecking.at(idx) = true;
				continue;
			}

			if(checking)
			{
				if (visitedWhileChecking.at(idx))
				{
					checking = false;
					visitedWhileChecking = std::vector<bool>(instructions.size(), 0);
					idx = -1;
					acc = 0;
					continue;
				} else
				{
					visitedWhileChecking.at(idx) = true;
				}
			}
			visited.at(idx) = true; 
			idx += cmd.second-1;
		}
	}
	std::cout << "The command with which the loop finishes is: " << testedCommand.first << " " << testedCommand.second << std::endl << "Acc: " << acc << std::endl;
	return 0;
}
