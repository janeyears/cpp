#pragma once
#include <iostream>

class Bureaucrat;

class AForm{
	public:
		AForm(std::string name, int gradeToSign, int gradeToExecute);
		AForm(const AForm &other);
		AForm &operator=(const AForm &other);
		virtual ~AForm();

		const int getGradeToSign() const;
		const int getGradeToExecute() const;
		const std::string getFormName() const;
		bool isSigned() const;

		void beSigned(Bureaucrat &b);

		void execute(Bureaucrat const &executor) const;

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

	class FormNotSignedException : public std::exception
	{
		public:
			const char *what( void ) const throw();
	};

	protected:
		virtual void action() const = 0;

	private:
		const std::string _name;
		bool _signed;
		const int _gradeToSign;
		const int _gradeToExecute;
};

std::ostream &operator<<(std::ostream &out, const AForm &f);