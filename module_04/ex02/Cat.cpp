#include "Cat.hpp"

Cat::Cat() : AAnimal() {
	std::cout << "🐈 Cat default constructor has been called" << std::endl;
	this->type = "Cat";
	this->_brain = new Brain;
}

Cat::Cat(const Cat &other) : AAnimal(other) {
	std::cout << "🐈 Cat copy constructor has been called" << std::endl;
	this->type = other.type;
	this->_brain = new Brain(*other._brain); // deep copy of Brain
}

Cat& Cat::operator=(const Cat &other) {
	if (this != &other){
		if(this->_brain)
			delete this->_brain;
		this->type = other.type;
		this->_brain = new Brain(*other._brain);
	}
	std::cout << "🐈 Cat assignment operator has been called" << std::endl;
	return *this;
}

Cat::~Cat(){
	delete this->_brain;
	std::cout << "🐈 Cat destructor has been called" << std::endl;
}

void Cat::makeSound() const{
	std::cout << "🐈 Cat is saying: MEEEOOW" << std::endl;
}

Brain* Cat::getBrain() const
{
	return this->_brain;
}