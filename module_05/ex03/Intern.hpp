#pragma once
#include "AForm.hpp"
#include "Bureaucrat.hpp"


class Intern {
	public:
		Intern();
		Intern (const Intern &other);
		Intern &operator=(const Intern &other);
		~Intern();
		AForm* makeForm(std::string formName, std::string target);
};