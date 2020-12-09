#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

int main() {
	std::ifstream file ("input.in");
    std::string line;
	std::vector<long long> cipher;
	const std::size_t preambleLength {25};

	if (file.is_open())
	{
		while ( getline (file,line) )
        {
			cipher.push_back(std::stoll(line));
        }
        file.close();
  	}

	for(int i {preambleLength} ; i < cipher.size() ; ++i)
	{
		bool found = false;
		for(int j {1} ; j <= preambleLength ; ++j)
		{
			//std::cout << "i: " << i << " j: " << j << " i-j: " << i-j << std::endl;
			//std::cout << cipher.at(i) << " looking at " << cipher.at(i) -  cipher.at(i-j) << " subtracting " << cipher.at(i-j) << std::endl;
			std::vector<long long>::const_iterator first {cipher.begin()+(i-preambleLength)};
			std::vector<long long>::const_iterator last {cipher.begin()+i};
			std::vector<long long> vSlice (first, last);
			if(std::find(vSlice.begin(), vSlice.end(), cipher.at(i) - cipher.at(i-j)) != vSlice.end()) { std::cout << "Cipher match found at " << cipher.at(i) << std::endl; found = true; }
		}
		if(found == false) {std::cout << "Cipher broken at: " << cipher.at(i) << std::endl; break;}
	}

  	return 0;
}
