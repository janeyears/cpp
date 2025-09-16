#pragma once
#include <iostream>
#include "Form.hpp"

class Bureaucrat {

	public:

		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat &other);
		Bureaucrat &operator=(const Bureaucrat &other);
		~Bureaucrat();

		const std::string &getName() const;
		int getGrade() const;
		void incrementGrade();
		void decrementGrade();

		class GradeTooHighException : public std::exception
		{
			public:
				const char *what( void ) const throw();
		};
		
		class GradeTooLowException : public	std::exception
		{
			public:
				const char *what( void ) const throw();
		};

		void signForm(Form &f);

	private:

		const std::string _name;
		int _grade;
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &b);
