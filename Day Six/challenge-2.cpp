#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <numeric>

int main() {
	std::ifstream file ("input.in");
    std::string line;
    std::map<char, int> questions;
    std::vector<int> answers;
    int groupSize {0};
	if (file.is_open())
	{
		while ( getline (file,line) )
        {
            if(line.empty())
            {
                //std::cout << "Map size: " << questions.size() << std::endl;
                //std::cout << "Group size: " << groupSize << std::endl;
                int ret {0};
                for(auto elem : questions)
                {
                    //std::cout << elem.first << " : " <<  elem.second << std::endl;
                    if (elem.second == groupSize) ret++;
                }
                //std::cout << "End Value: " << ret << std::endl;
                answers.push_back(ret);
                questions.clear();
                groupSize = 0;
                ret = 0;
                continue;
            }
            
            groupSize++;
            for(auto letter : line) 
            {
                questions[letter]++;
            }
        }
        //std::cout << "Map size: " << questions.size() << std::endl;
        //std::cout << "Group size: " << groupSize << std::endl;
        int ret {0};
        for(auto elem : questions)
        {
            //std::cout << elem.first << " : " <<  elem.second << std::endl;
            if (elem.second == groupSize) ret++;
        }
        //std::cout << "End Value: " << ret << std::endl;
        answers.push_back(ret);
        questions.clear();
        groupSize = 0;
        ret = 0;
        file.close();
  	}
  	std::cout << "Sum of Answers: " << std::accumulate(answers.begin(), answers.end(), 0) << std::endl;
    return 0;
}
