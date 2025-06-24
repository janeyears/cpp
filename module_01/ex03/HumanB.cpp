#include "HumanB.hpp"

HumanB::HumanB(std::string name){
	this->_name = name;
}

HumanB::~HumanB(){};

void HumanB::attack(){
	if (this->_weapon == NULL)
	{
		std::cout << this->_name << " doesn't have any weapon" << std::endl;
		return;
	}
	std::cout << this->_name << " attacks with their " << this->_weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon &newWeapon){
	this->_weapon = &newWeapon;
}