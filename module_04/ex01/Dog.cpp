#include "Dog.hpp"

Dog::Dog() : Animal() {
	std::cout << "🐩 Dog default constructor has been called" << std::endl;
	this->type = "Dog";
	this->_brain = new Brain;
}

Dog::Dog(const Dog &other) : Animal(other) {
	std::cout << "🐩 Dog copy constructor has been called" << std::endl;
	this->type = other.type;
	this->_brain = new Brain(*other._brain); // deep copy of Brain
}

Dog& Dog::operator=(const Dog &other) {
	if (this != &other){
		if(this->_brain)
			delete this->_brain;
		this->type = other.type;
		this->_brain = new Brain(*other._brain);
	}
	std::cout << "🐩 Dog assignment operator has been called" << std::endl;
	return *this;
}

Dog::~Dog(){
	delete this->_brain;
	std::cout << "🐩 Dog destructor has been called" << std::endl;
}

void Dog::makeSound() const{
	std::cout << "🐩 Dog is saying: BAAARK" << std::endl;
}


Brain* Dog::getBrain() const
{
	return this->_brain;
}