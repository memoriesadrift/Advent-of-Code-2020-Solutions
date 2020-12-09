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
	long long vulnerableNum;

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
			if(std::find(vSlice.begin(), vSlice.end(), cipher.at(i) - cipher.at(i-j)) != vSlice.end()) { /*std::cout << "Cipher match found at " << cipher.at(i) << std::endl;*/ found = true; }
		}
		if(found == false) {std::cout << "Cipher broken at: " << cipher.at(i) << std::endl; vulnerableNum = cipher.at(i); break;}
	}

	for(int i {0} ; i < cipher.size() ; ++i)
	{
		long long sum {0};
		long long min {-1}, max {0};
		for(int j {i} ; j < cipher.size() ; ++j)
		{
			sum+= cipher.at(j);
			if (cipher.at(j) < min || min == -1) min = cipher.at(j);
			if (cipher.at(j) > max) max = cipher.at(j);
			if (sum > vulnerableNum) break;
			if (sum == vulnerableNum) {std::cout << "Sum found for " << vulnerableNum << "! Segment from " << cipher.at(i) << " to " << cipher.at(j) << " sums up to " << sum << " with min: " << min << " and max: " << max << ". Sum of min and max: "<< min+max <<std::endl; return 0; }
		}
	}

  	return 0;
}
