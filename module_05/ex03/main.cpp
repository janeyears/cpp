#include <iostream>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"
#include "Intern.hpp"

int main() {
	srand(time(NULL));

	try {
		std::cout << "CREATING BUREAUCRATS" << std::endl;
		Bureaucrat axel("Axel", 1);
		Bureaucrat jane("Jane", 137);
		Bureaucrat anton("Anton", 150);
		std::cout << axel << std::endl;
		std::cout << jane << std::endl;
		std::cout << anton << std::endl;

		// ----- Test: Intern Creates Forms -----
		std::cout << "\nINTERN CREATION" << std::endl;
		Intern someRandomIntern;

		AForm* f1 = someRandomIntern.makeForm("ShrubberyCreationForm", "office");
		AForm* f2 = someRandomIntern.makeForm("RobotomyRequestForm", "R2D2");
		AForm* f3 = someRandomIntern.makeForm("PresidentialPardonForm", "Bob");
		AForm* f4 = someRandomIntern.makeForm("UnknownForm", "nobody");

		if (f1) {
			anton.signForm(*f1);
			axel.executeForm(*f1);
			jane.signForm(*f1);
			axel.executeForm(*f1);
		}
		if (f2) {
			axel.signForm(*f2);
			axel.executeForm(*f2);
		}
		if (f3) {
			axel.signForm(*f3);
			axel.executeForm(*f3);
		}

		delete f1;
		delete f2;
		delete f3;
		delete f4; 

	} catch (std::exception &e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	return 0;
}