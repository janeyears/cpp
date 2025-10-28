#include "PmergeMe.hpp"


bool isPositiveInteger(const std::string &str) {
	if (str.empty())
		return false;
	for (char c : str) {
		if (!std::isdigit(c))
			return false;
	}
	unsigned long num = std::strtoul(str.c_str(), NULL, 10);
	if (num == 0 || num > std::numeric_limits<unsigned int>::max())
		return false;
	return true;
}

int main(int argc, char **argv) {
	if (argc < 2) {
		std::cerr << "Error: no numbers provided." << std::endl;
		return 1;
	}

	std::vector<unsigned int> input;

	for (int i = 1; i < argc; ++i) {
		std::string arg = argv[i];
		if (!isPositiveInteger(arg)) {
			std::cerr << "Error: invalid input '" << arg << "'." << std::endl;
			return 1;
		}
		input.push_back(static_cast<unsigned int>(std::stoul(arg)));
	}

	try {
		PmergeMe sorter(input);
		sorter.sortContainers();
	} catch (const std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
		return 1;
	}

	return 0;
}