#pragma once
#include <iostream>

class ScalarConverter {
	public:
		static void convert(const std::string &literal);
	private:
		ScalarConverter() = delete;
		ScalarConverter(const ScalarConverter &other) = delete;
		ScalarConverter &operator=(const ScalarConverter &other) = delete;
		~ScalarConverter() = delete;
};