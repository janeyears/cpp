#include <iostream>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

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

		// ----- Test 1: ShrubberyCreationForm -----

			std::cout << "\nSHRUBS" << std::endl;
			ShrubberyCreationForm shrub("garden");
			jane.signForm(shrub);
			jane.executeForm(shrub);
			axel.executeForm(shrub);
			
		// ----- Test 2: RobotomyRequestForm -----

			std::cout << "\nROBOTOMY" << std::endl;
			RobotomyRequestForm robot("Bender");
			axel.signForm(robot);
			for (int i = 0; i < 5; i++) {
				axel.executeForm(robot);
			}
		// ----- Test 3: PresidentialPardonForm -----

			std::cout << "\nPARDON" << std::endl;
			PresidentialPardonForm pardon("Ford Prefect");
			axel.signForm(pardon);
			axel.executeForm(pardon);

		// ----- Test 4: Exceptions -----
		
			std::cout << "\nEXCEPTIONS" << std::endl;
			ShrubberyCreationForm badForm("backyard");
			anton.signForm(badForm);
			axel.executeForm(badForm);

		} catch (std::exception &e) {
			std::cerr << "Exception caught: " << e.what() << std::endl;
		}
	return 0;
}