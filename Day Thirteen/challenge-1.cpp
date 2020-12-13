#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

int main() {
	std::ifstream file ("input.in");
    std::string line;
	int time;
	std::vector<int> busses;
	std::vector<int> departureTimes;

	int bestBus {0};
	int waitTime {9999};

	if (file.is_open())
	{
		bool firstLine {true};
		while (getline (file,line))
        {
			if(firstLine) { time = std::stoi(line); firstLine = false; continue;}
			
			std::stringstream ss(line);
			for (int i; ss >> i;) 
			{
				busses.push_back(i);    
				while (ss.peek() == ',' || ss.peek() == 'x') { ss.ignore(); }
			}	
        }
        file.close();
  	}

	for(auto bus : busses)
	{
		departureTimes.push_back(bus - (time % bus));
		if(bus-(time%bus) < waitTime) { bestBus = bus; waitTime = (bus-(time%bus)); }
	}

	std::cout << "The soonest departing bus is: " << bestBus << " in " << waitTime << " minutes. Result: " << bestBus*waitTime << std::endl;
  	return 0;
}
