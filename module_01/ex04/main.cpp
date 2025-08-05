#include <iostream>
#include <string>
#include <fstream>

int main(int ac, char **av){
	
	std::string filename;
	std::string newFile;
	std::string s1;
	std::string s2;
	
	if (ac != 4)
	{
		std::cerr << "Invalid arguments: filename, s1 and s2" << std::endl;
		return 1;
	}

	filename = av[1];
	newFile = filename + ".replace";
	s1 = av[2];
	s2 = av[3];

	if (s1.length() == 0 || s2.length() == 0)
	{
		std::cerr << "Strings can't be empty" << std::endl;
		return 1;
	}

	std::ifstream inFile(filename);
	if (!inFile.is_open())
	{
		std::cerr << "Can't open file" << filename << std::endl;
		return 1;
	}
} 