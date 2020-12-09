#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <numeric>

int main() {
	std::ifstream file ("test.in");
    std::string line;
    std::map<char, int> questions;
    std::vector<int> answers;

	if (file.is_open())
	{
		while ( getline (file,line) )
        {
            if(line.empty())
            {
                answers.push_back(questions.size());
                questions.clear();
                continue;
            }
            
            for(auto letter : line) 
            {
                questions[letter]++;
            }
        }
        answers.push_back(questions.size());
        file.close();
  	}
  	std::cout << "Sum of Answers: " << std::accumulate(answers.begin(), answers.end(), 0) << std::endl;
    return 0;
}
