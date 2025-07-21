#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("Basic WrongAnimal"){
	std::cout << "🦄 WrongAnimal default constructor has been called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other){
	*this = other;
	std::cout << "🦄 WrongAnimal copy constructor has been called" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal &other){
	if (this != &other)
		this->type = other.type;
	std::cout << "🦄 WrongAnimal assignment operator has been called" << std::endl;
	return *this;
}

WrongAnimal::~WrongAnimal(){
	std::cout << "🦄 WrongAnimal destructor has been called" << std::endl;
}

void WrongAnimal::makeSound() const{
	std::cout << "🦄 WrongAnimal is saying: HAHAHA" << std::endl;
}

std::string WrongAnimal::getType() const{
	return this->type;
}