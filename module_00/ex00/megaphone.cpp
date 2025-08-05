#include <iostream>
#include <cctype>

int main(int ac, char** av) {

	int i = 1;

	if (ac < 2) 
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return 0;
	}
	while (i < ac) 
	{
		std::string input = av[i];
		for (char& c : input) 
			std::cout << static_cast<char>(std::toupper(static_cast<unsigned char>(c)));
		i++;	
	}
	std::cout << std::endl;
	return 0;
}