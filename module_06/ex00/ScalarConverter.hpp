#pragma once
#include <iostream>

class ScalarConverter {
	public:
		static void convert(const std::string &literal);
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &other);
		ScalarConverter &operator=(const ScalarConverter &other);
		~ScalarConverter();

		static bool isCharLiteral(const std::string& s);
		static bool isIntLiteral(const std::string& s);
		static bool isFloatLiteral(const std::string& s);
		static bool isDoubleLiteral(const std::string& s);
		static bool isPseudoLiteral(const std::string& s);

		static void printConversions(double d);
		static void printPseudo(const std::string& s);
		static void impossibleAll();

};