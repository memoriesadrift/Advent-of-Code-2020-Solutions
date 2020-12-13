#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

long long findInverse(long long a, long long b) {
	long long b0 = b;
	long long x0 = 0;
	long long x1 = 1;
 
	if (b == 1) {
		return 1;
	}
 
	while (a > 1) {
		long long q = a / b;
		long long amb = a % b;
		a = b;
		b = amb;
 
		long long xqx = x1 - q * x0;
		x1 = x0;
		x0 = xqx;
	}
 
	if (x1 < 0) {
		x1 += b0;
	}
 
	return x1;
}

long long chinese_remainder_theorem(std::vector<long long> a, std::vector<long long> n)
{
	long long M = 1;
	for(auto elem : n) { M *= elem; };

	long long sum = 0;
	for(int i {0} ; i < n.size(); ++i)
	{
		long long Mi {M / n.at(i)};
		sum += a.at(i) * Mi * findInverse(Mi%n.at(i), n.at(i));
	}

	return sum % M;
}

int main() {
	std::ifstream file ("input.in");
    std::string line;
	long long time;
	int offset {0};
	std::vector<long long> busses;
	std::vector<long long> offsets;

	if (file.is_open())
	{
		bool firstLine {true};
		while (getline (file,line))
        {
			if(firstLine) { time = std::stoll(line); firstLine = false; continue;}
			
			std::stringstream ss(line);
			for (long long i; ss >> i;) 
			{
				busses.push_back(i);
				if(busses.size() == 1) { offsets.push_back(offset); }
				else { offsets.push_back(i - offset); }
				while (ss.peek() == ',' || ss.peek() == 'x') 
				{
					if(ss.peek() == 'x')
					{
						ss.ignore();
						continue;
					} 
					ss.ignore();
					offset++;
				}
			}	
        }
        file.close();
  	}

	for( auto e : offsets) { std::cout << e << " "; }
	std::cout << std::endl;
	for( auto e : busses) { std::cout << e << " "; }

	long long rem = chinese_remainder_theorem(offsets, busses);

	std::cout << "The time at which the buses will depart according to the schedule is: " << rem << std::endl;
  	return 0;
}
