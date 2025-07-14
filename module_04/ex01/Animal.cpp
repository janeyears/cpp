#include "Animal.hpp"

Animal::Animal() : type("Basic animal"){
	std::cout << "🐾 Animal default constructor has been called" << std::endl;
}

Animal::Animal(const Animal &other){
	*this = other;
	std::cout << "🐾 Animal copy constructor has been called" << std::endl;
}

Animal& Animal::operator=(const Animal &other){
	if (this != &other)
		this->type = other.type;
	std::cout << "🐾 Animal assignment operator has been called" << std::endl;
	return *this;
}

Animal::~Animal(){
	std::cout << "🐾 Animal destructor has been called" << std::endl;
}

void Animal::makeSound() const{
	std::cout << "🐾 Animal is saying: WUUAAAH" << std::endl;
}

std::string Animal::getType() const{
	return this->type;
}