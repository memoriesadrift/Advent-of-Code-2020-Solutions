#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

int main() {
	std::ifstream file ("input.in");
    std::string line;
	
	if (file.is_open())
	{
		while ( getline (file,line) )
        {
        }
        file.close();
  	}
  	return 0;
}
