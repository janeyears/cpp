#include "RPN.hpp"
#include <sstream>


RPN::RPN(std::string input){
	_input = input;
}

RPN::RPN(const RPN &other){
	*this = other;
}

RPN &RPN::operator=(const RPN &other){
	if (this != &other) {
		_input = other._input;
		_stack = other._stack;
	}
	return *this;
}

RPN::~RPN(){};

int RPN::calculate(){
	if (!parseCheck(_input))
		throw std::runtime_error("Error: parsing has failed. Check your input");
	fillStack(_input);
	return mathProcess();
}

bool RPN::parseCheck(std::string input) {
	for (char c : input) {
		if (!std::isdigit(c) && c != '+' && c != '-' &&
			c != '*' && c != '/' && c != ' ')
			return false;
	}
	return true;
}

void RPN::fillStack(std::string input){
	std::istringstream iss(input);
	std::string token;
	std::stack<long long> temp;

	while (iss >> token) {
		if (token.size() == 1 && std::isdigit(token[0]))
			temp.push(token[0] - '0');
		else if (token == "+" || token == "-" || token == "*" || token == "/")
			temp.push(static_cast<long long>(token[0])); // store operator ASCII
		else
			throw std::runtime_error("Error: Tokenization failed. Check your input");
	}

	while (!temp.empty()) {
		_stack.push(temp.top());
		temp.pop();
	}

}

int RPN::mathProcess() {
	std::stack<long long> calc;

	while (!_stack.empty()) {
		long long token = _stack.top();
		_stack.pop();

		if (token == '+' || token == '-' || token == '*' || token == '/') {
			if (calc.size() < 2)
				throw std::runtime_error("Error: Amount of operators doesn't match amount of numbers");

			long long b = calc.top(); calc.pop();
			long long a = calc.top(); calc.pop();

			switch (token) {
				case '+': calc.push(a + b); break;
				case '-': calc.push(a - b); break;
				case '*': calc.push(a * b); break;
				case '/':
					if (b == 0)
						throw std::runtime_error("Error: can't divide by zero");
					calc.push(a / b);
					break;
			}
		}
		else {
			calc.push(token);
		}
	}

	if (calc.size() != 1)
		throw std::runtime_error("Error: Amount of operators doesn't match amount of numbers");

	return static_cast<int>(calc.top());
}