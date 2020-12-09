#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <exception>

int main() {
	const std::vector<std::string> categories{"byr", "iyr", "eyr", "hgt", "hcl", "ecl", "pid", "cid"};
	const std::string hclValidInputs {"0123456789abcdef"};
	const std::vector<std::string> eclValidInputs {"amb", "blu", "brn", "gry", "grn", "hzl", "oth"};
	std::vector<int> answers;
	std::string line;
	std::set<std::string> foundCategories;
	std::size_t validPassports {0};

	std::ifstream file ("input.in");
	if (file.is_open())
	{
		while ( getline (file,line) )
	    	{

			for(std::size_t i {0} ; i < categories.size() ; ++i)
			{
				
				if (line.find(categories.at(i)) != std::string::npos) 
				{
					auto n = line.find(categories.at(i));
					std::string toValidate;
					switch(i)
					{
						case 0:
							toValidate = line.substr(n+4, 4);
							std::cout << "BYR Case: " << toValidate << std::endl;
							try
							{
								int numberToValidate = std::stoi(toValidate);
								if( numberToValidate >= 1920  && numberToValidate <= 2002) { foundCategories.insert(categories.at(i)); std::cout << "valid"; }
							} catch (std::exception& e)
							{
								continue;
							}
							break;
						case 1:
							toValidate = line.substr(n+4, 4);
							std::cout << "IYR Case: " << toValidate << std::endl;
							try
							{
								int numberToValidate = std::stoi(toValidate);
								if( numberToValidate >= 2010 && numberToValidate <= 2020) { foundCategories.insert(categories.at(i)); std::cout << "valid"; }
							} catch (std::exception& e)
							{
								continue;
							}
							break;
						case 2:
							toValidate = line.substr(n+4, 4);
							std::cout << "EYR Case: " << toValidate << std::endl;
							try
							{
								int numberToValidate = std::stoi(toValidate);
								if( numberToValidate >= 2020 && numberToValidate <= 2030) { foundCategories.insert(categories.at(i)); std::cout << "valid"; }
							} catch (std::exception& e)
							{
								continue;
							}
							break;
						case 3:
							toValidate = line.substr(n+4, 5);
							std::cout << "HGT Case: " << toValidate << std::endl;
							if (line.find("cm") != std::string::npos)
							{
								int numberToValidate = std::stoi(toValidate.substr(0, 3));
								if(numberToValidate >= 150 && numberToValidate <= 193) { foundCategories.insert(categories.at(i)); std::cout << "valid"; }
								continue;

							} else if (line.find("in") != std::string::npos)
							{
								int numberToValidate = std::stoi(toValidate.substr(0, 2));
								if(numberToValidate >= 59 && numberToValidate <= 76) { foundCategories.insert(categories.at(i)); std::cout << "valid"; }
								continue;
							} else
							{
								continue;
							}	
							break;
						case 4:
							{
								toValidate = line.substr(n+4);
								auto m = toValidate.find(" ");
								if(m == std::string::npos) m = toValidate.find("\n");
								if(m == std::string::npos) continue;
								toValidate = toValidate.substr(0, m-(n+4));

								if(toValidate.size() > 7) continue;
								std::cout << "HCL Case: " << toValidate << std::endl;
								if(toValidate.at(0) != '#') continue;
								std::cout << "validating hcl" << std::endl;
								for(int idx {1} ; idx < toValidate.size() ; ++idx)
								{
									std::cout<< toValidate.at(idx) <<std::endl;
									if(hclValidInputs.find(toValidate.at(idx)) == std::string::npos) continue;
								}	
								foundCategories.insert(categories.at(i));
								std::cout << "valid";
								break;
							}
						case 5:
							toValidate = line.substr(n+4, 3);
							std::cout << "ECL Case: " << toValidate << std::endl;
							if(std::find(eclValidInputs.begin(), eclValidInputs.end(), toValidate) != eclValidInputs.end()) { foundCategories.insert(categories.at(i)); std::cout << "valid"; }
							break;
						case 6:
							{
								toValidate = line.substr(n+4);
								std::cout << "PID Case: " << toValidate << std::endl;
								auto m = toValidate.find(" ");
								if(m == std::string::npos) m = toValidate.find("\n");
								if(m == std::string::npos) continue;
								toValidate = toValidate.substr(0, m-(n+4));
								if(toValidate.size() > 9) continue;
								try
								{
									std::stoi(toValidate);
									foundCategories.insert(categories.at(i));
									std::cout << "valid";
								} catch (std::exception& e)
								{
									continue;
								}
								break;
							}
						default:
							continue;
							break;
					}
				}
			}

			if(line.empty())
			{
				std::cout << "Empty line! foundCategories size: " << foundCategories.size() << std::endl;
				answers.push_back(foundCategories.size());
				if(foundCategories.size() == 8) { validPassports++; }
				else if (foundCategories.size() == 7 && foundCategories.find("cid") == foundCategories.end()) { validPassports++; std::cout << "found a 7 w missing cid" << std::endl; }
				foundCategories.clear();
				continue;
			}
    		}
    		file.close();
  	}
	
	std::cout << "Valid Passports: " << validPassports << std::endl;
	std::cout << "Valid Passports, recount: " << std::count_if(answers.begin(), answers.end(), [](int i) { return (i == 7 || i == 8); }) << std::endl;
  	return 0;
}
