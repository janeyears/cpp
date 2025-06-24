#include "Weapon.hpp"

Weapon::Weapon(){};
Weapon::~Weapon(){};

Weapon::Weapon(std::string type)
{
	this->_type = type;
	return;
}

const std::string& Weapon::getType(){
	return this->_type;
}

void Weapon::setType(std::string newType){
	this->_type = newType;
}