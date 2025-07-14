#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("Default") {
	this->_name = "Default";
	this->_health = 100;
	this->_energy = 100;
	this->_damage = 30;
	std::cout << "FragTrap " << _name << " is default constructed!" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	this->_name = name;
	this->_health = 100;
	this->_energy = 100;
	this->_damage = 30;
	std::cout << "FragTrap " << name << " is constructed!" << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other) {
	std::cout << "FragTrap " << _name << " is copy constructed!" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other) {
	if (this != &other) {
		ClapTrap::operator=(other);
	}
	std::cout << "FragTrap " << _name << " assigned via copy assignment operator!" << std::endl;
	return *this;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap " << _name << " has been destroyed!" << std::endl;
}

void FragTrap::highFivesGuys() {
	std::cout << "FragTrap " << this->_name << " requests: High fives, guys! ✋" << std::endl;
}

