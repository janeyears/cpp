#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal() {
	this->type = "WrongCat";
	std::cout << "🦁 WrongCat default constructor has been called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other) {
	*this = other;
	std::cout << "🦁 WrongCat copy constructor has been called" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat &other) {
	this->type = other.type;
	std::cout << "🦁 WrongCat assignment operator has been called" << std::endl;
	return *this;
}

WrongCat::~WrongCat(){
	std::cout << "🦁 WrongCat destructor has been called" << std::endl;
}

void WrongCat::makeSound() const{
	std::cout << "🦁 WrongCat is saying: ?%#?&^@" << std::endl;
}