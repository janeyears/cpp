#include "AAnimal.hpp"

AAnimal::AAnimal() : type("Basic AAnimal"){
	std::cout << "🐾 AAnimal default constructor has been called" << std::endl;
}

AAnimal::AAnimal(const AAnimal &other){
	*this = other;
	std::cout << "🐾 AAnimal copy constructor has been called" << std::endl;
}

AAnimal& AAnimal::operator=(const AAnimal &other){
	if (this != &other)
		this->type = other.type;
	std::cout << "🐾 AAnimal assignment operator has been called" << std::endl;
	return *this;
}

AAnimal::~AAnimal(){
	std::cout << "🐾 AAnimal destructor has been called" << std::endl;
}

std::string AAnimal::getType() const{
	return this->type;
}