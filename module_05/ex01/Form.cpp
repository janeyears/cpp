#include "Form.hpp"
#include "Bureaucrat.hpp"

const char	*Form::GradeTooHighException::what( void ) const throw()
{
	return ("Grade too high!");
}

const char	*Form::GradeTooLowException::what( void ) const throw()
{
	return ("Grade too low!");
}

Form::Form(std::string name, int gradeToSign, int gradeToExecute) 
		: _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
	{
		if (_gradeToExecute > 150 || _gradeToSign > 150)
			throw GradeTooLowException();
		if (_gradeToExecute < 1 || _gradeToSign < 1)
			throw GradeTooHighException();
	}

Form::Form(const Form &other):_signed(other._signed), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute){}

Form& Form::operator=(const Form &other){
	if (this != &other)
		this->_signed = other._signed;
	return *this;
}

Form::~Form(){}

const int Form::getGradeToSign() const{
	return this->_gradeToSign;
}
const int Form::getGradeToExecute() const{
	return this->_gradeToExecute;
}
const std::string Form::getFormName() const{
	return this->_name;
}

std::ostream &operator<<(std::ostream &out, const Form &f) {
	out << f.getFormName() << ", form with grade to sign: " << f.getGradeToSign() << " and grade to execute: " <<  f.getGradeToExecute() << "." << std::endl;
	return out;
}



void Form::beSigned(Bureaucrat &b){
	int bGrade = b.getGrade();
	if (bGrade > this->getGradeToSign())
		throw GradeTooLowException();
	this->_signed = true;
}
