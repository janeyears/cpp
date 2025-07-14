#include "Dog.hpp"

Dog::Dog() : Animal() {
	this->type = "Dog";
	std::cout << "🐩 Dog default constructor has been called" << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other) {
	*this = other;
	std::cout << "🐩 Dog copy constructor has been called" << std::endl;
}

Dog& Dog::operator=(const Dog &other) {
	this->type = other.type;
	std::cout << "🐩 Dog assignment operator has been called" << std::endl;
	return *this;
}

Dog::~Dog(){
	std::cout << "🐩 Dog destructor has been called" << std::endl;
}

void Dog::makeSound() const{
	std::cout << "🐩 Dog is saying: BAAARK" << std::endl;
}