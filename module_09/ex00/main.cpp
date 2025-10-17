#include  "BitcoinExchange.hpp"
#include <iostream>

int main(int argc, char **argv) {
	if (argc != 2) {
		std::cerr << "Error: Usage" << std::endl;
		return 1;
	}

	// Create and initialize the BitcoinExchange object with database
	Btc btc("data.csv");

	// Process the input file
	btc.processInput(argv[1]);

	return 0;
}