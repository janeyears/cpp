#include <iostream>
#include "Bureaucrat.hpp"

int main() {
	// ----- Test 1: valid Bureaucrat -----
	try {
		Bureaucrat b1("Axel", 42);
		std::cout << b1 << std::endl;
	}
	catch (const std::exception &e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	// ----- Test 2: grade too high -----
	try {
		Bureaucrat b2("Anton", 0); // invalid grade
	}
	catch (const Bureaucrat::GradeTooHighException &e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	// ----- Test 3: grade too low -----
	try {
		Bureaucrat b3("Jane", 200); // invalid grade
	}
	catch (const Bureaucrat::GradeTooLowException &e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	// ----- Test 4: decrementing grade -----

	Bureaucrat b4("Bob", 149);
	try {
		b4.decrementGrade();
		std::cout << b4 << std::endl;
		b4.decrementGrade();
	}
	catch (const Bureaucrat::GradeTooLowException &e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	// ----- Test 5: incrementing grade -----

	Bureaucrat b5("Lena", 2);
	try {
		b5.incrementGrade();
		std::cout << b5 << std::endl;
		b5.incrementGrade();
	}
	catch (const Bureaucrat::GradeTooHighException &e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	return 0;
}