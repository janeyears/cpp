#include "RPN.hpp"

int main(int argc, char **argv) {
	if (argc != 2) {
		std::cerr << "Error: Usage: ./RPN \"2 3 +\"" << std::endl;
		return 1;
	}

	try {
		RPN rpn(argv[1]);
		std::cout << rpn.calculate() << std::endl;
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
		return 1;
	}

	return 0;
}