#include "Bureaucrat.hpp"

const char	*Bureaucrat::GradeTooHighException::what( void ) const throw()
{
	return ("Exception: Grade too high!");
}

const char	*Bureaucrat::GradeTooLowException::what( void ) const throw()
{
	return ("Exception: Grade too low!");
}


Bureaucrat::Bureaucrat(std::string name, int grade) 
		: _name(name), _grade(grade)
{
	if (grade > 150)
		throw GradeTooLowException();
	if (grade < 1)
		throw GradeTooHighException();
	std::cout << "Bureaucrat " << this->_name << " with grade " << this->_grade << " has been constructed" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) 
		: _name(other._name), _grade(other._grade){}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &other){
	if (this != &other) {
		this->_grade = other._grade;
	}
	return *this;
}

Bureaucrat::~Bureaucrat() {}

const std::string &Bureaucrat::getName() const {
	return this->_name;
}

int Bureaucrat::getGrade() const{
	return this->_grade;
}
void Bureaucrat::incrementGrade(){
	if (this->_grade == 1)
		throw GradeTooHighException();
	this->_grade -= 1;
}
void Bureaucrat::decrementGrade(){
	if (this->_grade == 150)
		throw GradeTooLowException();
	this->_grade += 1;
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &b) {
	out << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
	return out;
}