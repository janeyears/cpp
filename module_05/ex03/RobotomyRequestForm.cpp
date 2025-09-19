#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target)
	: AForm("RobotomyRequestForm", 72, 45) {
		this->_target = target;
	}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
	: AForm(other), _target(other._target) {}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other){
	if (this != &other)
	{
		AForm::operator = (other);
		_target = other._target;
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm(){};

void RobotomyRequestForm::action() const {
	std::cout << "* DRILLING NOISES *\n";
	if (rand() % 2)
		std::cout << _target << " has been robotomized successfully! :)\n";
	else
		std::cout << "Robotomy failed on " << _target << " :(\n";
}