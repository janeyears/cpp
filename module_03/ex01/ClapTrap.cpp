#include "ClapTrap.hpp"

// Default constructor
ClapTrap::ClapTrap() : _name("Default"), _energy(10), _health(10), _damage(0)
{
	std::cout << "ClapTrap " << _name << " default constructed!" << std::endl;
}

// Parameterized constructor
ClapTrap::ClapTrap(std::string name) : _name(name), _energy(10), _health(10), _damage(0)
{
	std::cout << "ClapTrap " << name << " constructed!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other) {
	*this = other;
	std::cout << "ClapTrap " << _name << " copy constructed!" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &other) {
	if (this != &other) {
		this->_name = other._name;
		this->_damage = other._damage;
		this->_energy = other._energy;
		this->_health = other._health;
	}
	std::cout << "ClapTrap " << _name << " assigned via copy assignment operator!" << std::endl;
	return *this;
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap " << _name << " has been destroyed!" << std::endl;
}

void ClapTrap::attack(const std::string& target){
	if (this->_energy == 0) {
		std::cout << "ClapTrap " << _name << " is out of energy points" << std::endl;
		return;
	}
	if (this->_health == 0) {
		std::cout << "ClapTrap " << _name << " can't attack because it is dead" << std::endl;
		return;
	}
	_energy -= 1;
	std::cout << "ClapTrap " << _name << " attacks " << target << " causing " << _damage << " damage points" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (_health <= amount) {
		std::cout << "ClapTrap " << _name << " took " << amount << " points of damage and now it is dead" << std::endl;
		_health = 0;
		return;
	}
	_health -= amount;
	if (_health < 0) {
		_health = 0;
	}
	std::cout << "ClapTrap " << _name << " took " << amount << " points of damage" << std::endl;

}
void ClapTrap::beRepaired(unsigned int amount){
	if (this->_energy == 0) {
		std::cout << "ClapTrap " << _name << " is out of energy points" << std::endl;
		return;
	}
	if (this->_health == 0) {
		std::cout << "ClapTrap " << _name << " is already dead, can't be repaired" << std::endl;
		return;
	}
	_health += amount;
	_energy -= 1;
	std::cout << "ClapTrap " << _name << " repaired itself for " << amount << " hit points. Total hit points: " << _health << std::endl;

}
