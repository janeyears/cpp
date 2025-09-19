#include "ShrubberyCreationForm.hpp"
#include <fstream>
#include <cstring>

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
	: AForm("ShrubberyCreationForm", 145, 137) {
		this->_target = target;
	}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
	: AForm(other), _target(other._target) {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other){
	if (this != &other)
	{
		AForm::operator = (other);
		_target = other._target;
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::action() const {
	std::ofstream file(_target + "_shrubbery");
	if (file.is_open()) {
		file << "   ^           ^ \n"
			<< "  /|\\         /|\\ \n"
			<< " //|\\\\       //|\\\\ \n"
			<< "   |           |  \n";
	}
	else {
		throw (std::runtime_error("Cannot open '" + _target + "_shrubbery': " + strerror(errno)));
	}
	file.close();
}