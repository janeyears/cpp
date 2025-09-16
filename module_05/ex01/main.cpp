#include <iostream>
#include "Bureaucrat.hpp"


int main() {

// ----- Test 1: Successful sign -----

	try {
		Bureaucrat b2("Bob", 1);
		Form f1("Contract with the Devil", 40, 120);
		b2.signForm(f1);

	}
	catch (const std::exception &e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}


// ----- Test 2: Failed sign -----
	try {
		Bureaucrat b1("Alice", 42);
		Form f2("Contract with the Devil", 40, 120);
		b1.signForm(f2);

	}
	catch (const std::exception &e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

// ----- Test 3: Creating form out of scope -----

	try {
		Form f3("Tax form", 151, 2);
	}
	catch (const std::exception &e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

// ----- Test 4: Creating normal form -----

	try {
		Form f4("Tax form", 114, 132);
		std::cout << f4;
	}
	catch (const std::exception &e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}


	return 0;
}