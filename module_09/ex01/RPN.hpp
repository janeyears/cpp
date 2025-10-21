#pragma once
#include <stack>
#include <iostream>

class RPN {
	public:
		RPN(std::string input);
		RPN(const RPN &other);
		RPN &operator=(const RPN &other);
		~RPN();
		int calculate();
	private:
		std::stack<long long> _stack;
		std::string _input;

		bool parseCheck(std::string input);
		void fillStack(std::string input);
		int mathProcess();
};