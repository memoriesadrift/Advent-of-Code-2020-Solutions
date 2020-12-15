#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

int main() {
	std::ifstream file ("input.in");
    std::string line;
	std::map<int, int> numbers;
	std::vector<int> startingInput;
	
	if (file.is_open())
	{
		while ( getline (file,line) )
        {
			std::stringstream ss(line);
			int counter {0};
			for (int i; ss >> i;) 
			{
				startingInput.push_back(i);
				if (ss.peek() == ',') ss.ignore();
			}	
        }
        file.close();
  	}

	for(int i {1}; i <= startingInput.size() ; ++i)
	{
		if(i-2 >= 0) numbers[startingInput.at(i-2)] = i-1;
		numbers[startingInput.at(i-1)] = 0;
	}

	int currentNumber {-1}, previousNumber {startingInput.back()};
	for(int turn {startingInput.size()+1} ; turn <= 30000000 ; ++turn)
	{
		if(numbers[previousNumber] > 0)
		{
			currentNumber = turn-1 - numbers[previousNumber];
			numbers[previousNumber] = turn-1;
		} else 
		{
			currentNumber = 0;
			numbers[previousNumber] = turn-1;
		}

		previousNumber = currentNumber;
	}
	std::cout << "Result: " << currentNumber << std::endl;
  	return 0;
}
