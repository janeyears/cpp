#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <sstream>

void Btc::processInput(const std::string &inputFile) {
	std::ifstream input(inputFile.c_str());
	if (!input.is_open()) {
		std::cerr << "Error: could not open file." << std::endl;
		return;
	}

	std::string line;
	// skip header
	std::getline(input, line);

	while (std::getline(input, line)) {
		if (line.empty())
			continue;

		std::stringstream ss(line);
		std::string date, valueStr;

		if (!std::getline(ss, date, '|')) {
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}

		date = trim(date);
		if (!std::getline(ss, valueStr)) {
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}
		valueStr = trim(valueStr);

		if (!isValidDate(date)) {
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}

		if (!isNumber(valueStr)) {
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}

		double value = std::stod(valueStr);
		if (value < 0) {
			std::cerr << "Error: not a positive number." << std::endl;
			continue;
		}
		if (value > 1000) {
			std::cerr << "Error: too large a number." << std::endl;
			continue;
		}

		double rate;
		if (!findRate(date, rate)) {
			std::cerr << "Error: no data available before " << date << std::endl;
			continue;
		}

		double result = value * rate;
		std::cout << date << " => " << value << " = "
				  << std::fixed << std::setprecision(1) << result << std::endl;
	}
}

bool Btc::isValidDate(const std::string &date) const {
	if (date.size() != 10 || date[4] != '-' || date[7] != '-') return false;
	int year, month, day;
	try {
		year = std::stoi(date.substr(0, 4));
		month = std::stoi(date.substr(5, 2));
		day = std::stoi(date.substr(8, 2));
	} catch (...) {
		return false;
	}
	if (month < 1 || month > 12 || day < 1) return false;

	int daysInMonth[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	bool leap = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
	if (month == 2 && leap) {
		if (day > 29) return false;
	} else {
		if (day > daysInMonth[month - 1]) return false;
	}
	return true;
}

bool Btc::isNumber(const std::string &str) const {
	if (str.empty()) 
		return false;
	size_t i = 0;
	if (str[0] == '-') {
		if (str.size() == 1) 
			return false; // just '-' is not a number
		i = 1;
	}

	bool dotFound = false;
	for (; i < str.size(); ++i) {
		if (str[i] == '.') {
			if (dotFound) return false;
			dotFound = true;
		} else if (!isdigit(str[i])) {
			return false;
		}
	}
	return true;
}


bool Btc::findRate(const std::string &date, double &rate) const {
	std::map<std::string, double>::const_iterator i = _data.lower_bound(date);
	if (i != _data.end() && i->first == date) {
		rate = i->second;
		return true;
	}
	if (i == _data.begin())
		return false;
	--i;
	rate = i->second;
	return true;
}

std::string Btc::trim(const std::string &s) const {
	size_t start = s.find_first_not_of(" \t");
	if (start == std::string::npos) return "";
	size_t end = s.find_last_not_of(" \t");
	return s.substr(start, end - start + 1);
}

bool Btc::loadDatabase(const std::string &dbFile){
	std::ifstream file(dbFile.c_str());
	if (!file.is_open())
		return false;
	std::string line;

	std::getline(file, line); // skip header

	while (std::getline(file, line)) {
		std::stringstream ss(line);
		std::string date, rate;
		if (!std::getline(ss, date, ',')) 
			continue;
		if (!std::getline(ss, rate)) 
			continue;

		date = trim(date);
		rate = trim(rate);
		if (!isValidDate(date)) continue;

		try {
			double rateValue = std::stod(rate);
			_data[date] = rateValue;
		} catch (...) {
			continue;
		}
	}
	return true;
}

Btc::Btc(const std::string &dbFile) {
	if (!loadDatabase(dbFile)) {
		std::cerr << "Error: could not open database file." << std::endl;
		exit(1);
	}
}

Btc::~Btc(){}