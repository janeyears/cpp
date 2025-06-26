#include <iostream>
#include <fstream>
#include <string>

void searchAndReplace(std::string s1, std::string s2, std::ifstream& infd, std::ofstream& outfd){
	std::string buffer;
	size_t i;
	
	while(std::getline(infd, buffer))
	{
		i = 0;
		while((i = buffer.find(s1, i)) != std::string::npos)
		{
			buffer.erase(i, s1.length());
			buffer.insert(i, s2);
			i += s2.length();
		}
		outfd << buffer << "\n";
	}
}

int main (int ac, char **av){
	if (ac != 4)
	{
		std::cerr << "Invalid number of arguments. Try: filename, s1, s2" << std::endl;
		return 1;
	}

	std::string filename = av[1];
	std::string s1 = av[2];
	std::string s2 = av[3];

	if (filename.length() == 0 || s1.length() == 0 || s2.length() == 0)
	{
		std::cerr << "Arguments can't be empty strings" << std::endl;
		return 1;
	}

	std::ifstream inputfd(filename);
	if (!inputfd.is_open())
	{

		std::cerr << "Can't open " << filename << std::endl;
		return 1;
	}

	std::string output = filename + ".replace";
	std::ofstream outputfd(output);
	if(!outputfd.is_open())
	{
		std::cerr << "Can't create" << output << std::endl;
		inputfd.close();
		return 1;
	}
	searchAndReplace(s1, s2, inputfd, outputfd);
	return 0;
}