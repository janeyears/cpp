#include "Cat.hpp"

Cat::Cat() : Animal() {
	this->type = "Cat";
	std::cout << "🐈 Cat default constructor has been called" << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other) {
	*this = other;
	std::cout << "🐈 Cat copy constructor has been called" << std::endl;
}

Cat& Cat::operator=(const Cat &other) {
	this->type = other.type;
	std::cout << "🐈 Cat assignment operator has been called" << std::endl;
	return *this;
}

Cat::~Cat(){
	std::cout << "🐈 Cat destructor has been called" << std::endl;
}

void Cat::makeSound() const{
	std::cout << "🐈 Cat is saying: MEEEOOW" << std::endl;
}