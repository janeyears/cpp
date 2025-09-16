#pragma once
#include <iostream>

class Bureaucrat;

class Form{
	public:
		Form(std::string name, int gradeToSign, int gradeToExecute);
		Form(const Form &other);
		Form &operator=(const Form &other);
		~Form();

		const int getGradeToSign() const;
		const int getGradeToExecute() const;
		const std::string getFormName() const;

		void beSigned(Bureaucrat &b);


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

	private:
		const std::string _name;
		bool _signed;
		const int _gradeToSign;
		const int _gradeToExecute;
};

std::ostream &operator<<(std::ostream &out, const Form &f);