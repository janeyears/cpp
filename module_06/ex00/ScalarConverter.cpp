#include "ScalarConverter.hpp"
#include <iomanip>
#include <limits>
#include <cmath>


ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter&) {}
ScalarConverter& ScalarConverter::operator=(const ScalarConverter&) { return *this; }
ScalarConverter::~ScalarConverter() {}

bool ScalarConverter::isCharLiteral(const std::string& s) {
	return (s.size() == 1 && !std::isdigit(s[0]));
}

bool ScalarConverter::isIntLiteral(const std::string& s) {
	size_t i = 0;
	if (s[i] == '-' || s[i] == '+') 
		i++;
	if (i >= s.size()) 
		return false;
	for (; i < s.size(); i++) if (!std::isdigit(s[i])) 
		return false;
	return true;
}

bool ScalarConverter::isFloatLiteral(const std::string& s) {
	return (s == "-inff" || s == "+inff" || s == "inff" || s == "nanf" ||
		   (s.back() == 'f' && s.find('.') != std::string::npos));
}

bool ScalarConverter::isDoubleLiteral(const std::string& s) {
	return (s == "-inf" || s == "+inf" || s == "inf" || s == "nan" ||
			(s.find('.') != std::string::npos));
}

bool ScalarConverter::isPseudoLiteral(const std::string& s) {
	return (s == "-inff" || s == "+inff" || s == "inff" || s == "nanf" ||
			s == "-inf"  || s == "+inf"  || s == "inf" || s == "nan");
}

// --------------------
// Printers
// --------------------
void ScalarConverter::printConversions(double d) {
	// char
	std::cout << "char: ";
	if (std::isnan(d) || d < std::numeric_limits<char>::min() || d > std::numeric_limits<char>::max())
		std::cout << "impossible\n";
	else if (!std::isprint(static_cast<char>(d)))
		std::cout << "Non displayable\n";
	else
		std::cout << "'" << static_cast<char>(d) << "'\n";

	// int
	std::cout << "int: ";
	if (std::isnan(d) || d < std::numeric_limits<int>::min() || d > std::numeric_limits<int>::max())
		std::cout << "impossible\n";
	else
		std::cout << static_cast<int>(d) << "\n";

	// float
	std::cout << "float: ";
	if (std::isnan(d) || d < -std::numeric_limits<float>::max() || d > std::numeric_limits<float>::max())
		std::cout << "impossible\n";
	else {
		int precision = (d == static_cast<int>(d)) ? 1 : 6;
		std::cout << std::fixed << std::setprecision(precision)
				<< static_cast<float>(d) << "f\n";
	}

	// double
	std::cout << "double: ";
	{
		int precision = (d == static_cast<int>(d)) ? 1 : 6;
		std::cout << std::fixed << std::setprecision(precision) << d << "\n";
	}
}


void ScalarConverter::printPseudo(const std::string& s) {
	std::cout << "char: impossible\nint: impossible\n";
	if (s == "nanf" || s == "+inff" || s == "inff" || s == "-inff") {
		std::cout << "float: " << s << "\n";
		std::cout << "double: " << s.substr(0, s.size() - 1) << "\n";
	} else {
		std::cout << "float: " << s << "f\n";
		std::cout << "double: " << s << "\n";
	}
}

void ScalarConverter::impossibleAll() {
	std::cout << "char: impossible\n"
			  << "int: impossible\n"
			  << "float: impossible\n"
			  << "double: impossible\n";
}


void ScalarConverter::convert(const std::string &literal) {
	if (isCharLiteral(literal)) {
		char c = literal[0];
		double d = static_cast<double>(c);
		printConversions(d);
	}
	else if (isIntLiteral(literal)) {
		try {
			long long val = std::stoll(literal); // bigger than int
			double d = static_cast<double>(val);
			printConversions(d);
		} 
		catch (const std::out_of_range&) {
			// If it's too big for int, still try as double
			try {
				double d = std::stod(literal);
				printConversions(d); // will print "int: impossible" inside
			}
			catch (...) {
				impossibleAll();
			}
		}
		catch (...) {
			impossibleAll();
		}
	}
	else if (isFloatLiteral(literal)) {
		if (isPseudoLiteral(literal)) { 
			printPseudo(literal); 
			return; 
		}
		try {
			double d = std::stod(literal);
			printConversions(d);
		} catch (...) { 
			impossibleAll(); 
		}
	}
	else if (isDoubleLiteral(literal)) {
		if (isPseudoLiteral(literal)) { 
			printPseudo(literal); 
			return; 
		}
		try {
			double d = std::stod(literal);
			printConversions(d);
		} catch (...) { 
			impossibleAll();
		}
	}
	else {
		impossibleAll();
	}
}

// inff = +inff
// inf = +inf
// check until float max and max double