#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern(){}

Intern::Intern (const Intern &other){}

Intern& Intern::operator=(const Intern &other){
	return *this;
}
Intern::~Intern(){}

AForm* Intern::makeForm(std::string formName, std::string target){
	std::string forms[3] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};
	for (int i = 0; i <= 3; i++)
	{
		if (forms[i] == formName)
			switch (i)
			{
			case 0:
				std::cout << "Intern creates " << formName << std::endl;
				return (new ShrubberyCreationForm(target));
			case 1:
				std::cout << "Intern creates " << formName << std::endl;
				return (new RobotomyRequestForm(target));
			case 2:
				std::cout << "Intern creates " << formName << std::endl;
				return (new PresidentialPardonForm(target));
			default:
				return NULL;
			}
	}
	std::cout << "Intern can't create " << formName << std::endl;
	return NULL;
}

