#include "BitcoinExchange.hpp"
#include <iostream>

Btc::Btc(const std::string &dbFile) {
	if (!loadDatabase(dbFile)) {
		std::cerr << "Error: could not open database file." << std::endl;
		exit(1);
	}
}

bool Btc::loadDatabase(const std::string &dbFile){
	
}