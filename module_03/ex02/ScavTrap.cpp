#include "ScavTrap.hpp"

#include "ScavTrap.hpp"

	ScavTrap::ScavTrap() : ClapTrap("Default") {
		this->_name = "Default";
		this->_health = 100;
		this->_energy = 50;
		this->_damage = 20;
		std::cout << "ScavTrap " << _name << " is default constructed!" << std::endl;
	}

	ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
		this->_name = name;
		this->_health = 100;
		this->_energy = 50;
		this->_damage = 20;
		std::cout << "ScavTrap " << name << " is constructed!" << std::endl;
	}

	ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other) {
		std::cout << "ScavTrap " << _name << " is copy constructed!" << std::endl;
	}

	ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
		if (this != &other) {
			ClapTrap::operator=(other); // Call base assignment operator
		}
		std::cout << "ScavTrap " << _name << " assigned via copy assignment operator!" << std::endl;
		return *this;
	}

	ScavTrap::~ScavTrap() {
		std::cout << "ScavTrap " << _name << " has been destroyed!" << std::endl;
	}

	void ScavTrap::attack(const std::string& target) {
		if (this->_energy == 0) {
			std::cout << "ScavTrap " << _name << " is out of energy points" << std::endl;
			return;
		}
		if (this->_health == 0) {
			std::cout << "ScavTrap " << _name << " can't attack because it is dead" << std::endl;
			return;
		}
		_energy -= 1;
		std::cout << "ScavTrap " << _name << " attacks " << target << " causing " << _damage << " damage points" << std::endl;
	}

	void ScavTrap::guardGate() {
		if (this->_energy == 0) {
			std::cout << "ScavTrap " << _name << " is out of energy points" << std::endl;
			return;
		}
		if (this->_health == 0) {
			std::cout << "ScavTrap " << _name << " can't be in Gate keeper mode because it is dead" << std::endl;
			return;
		}
		std::cout << "ScavTrap " << this->_name << " is now in Gate keeper mode." << std::endl;
	}