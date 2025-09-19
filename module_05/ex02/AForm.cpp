#include "AForm.hpp"
#include "Bureaucrat.hpp"

const char	*AForm::GradeTooHighException::what( void ) const throw()
{
	return ("Grade too high!");
}

const char	*AForm::GradeTooLowException::what( void ) const throw()
{
	return ("Grade too low!");
}

const char	*AForm::FormNotSignedException::what( void ) const throw()
{
	return ("Form is not signed yet!");
}

AForm::AForm(std::string name, int gradeToSign, int gradeToExecute) 
		: _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
	{
		if (_gradeToExecute > 150 || _gradeToSign > 150)
			throw GradeTooLowException();
		if (_gradeToExecute < 1 || _gradeToSign < 1)
			throw GradeTooHighException();
	}

AForm::AForm(const AForm &other):_signed(other._signed), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute){}

AForm& AForm::operator=(const AForm &other){
	if (this != &other)
		this->_signed = other._signed;
	return *this;
}

AForm::~AForm(){}

const int AForm::getGradeToSign() const{
	return this->_gradeToSign;
}
const int AForm::getGradeToExecute() const{
	return this->_gradeToExecute;
}
const std::string AForm::getFormName() const{
	return this->_name;
}

bool AForm::isSigned() const{
	if (this->_signed == true)
		return true;
	else
		return false;
}

std::ostream &operator<<(std::ostream &out, const AForm &f) {
	out << f.getFormName() << ", form with grade to sign: " << f.getGradeToSign() << " and grade to execute: " <<  f.getGradeToExecute() << "." << std::endl;
	return out;
}

void AForm::beSigned(Bureaucrat &b){
	int bGrade = b.getGrade();
	if (bGrade > this->getGradeToSign())
		throw GradeTooLowException();
	this->_signed = true;
}

void AForm::execute(Bureaucrat const &executor) const {
	if (!this->isSigned())
		throw FormNotSignedException();
	if (executor.getGrade() > _gradeToExecute)
		throw GradeTooLowException();
	action();
}
