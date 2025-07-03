#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>


class ClapTrap {
	private:
		std::string _name;
		int _health;
		int _energy;
		int _damage;
	public:
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap &other);
		ClapTrap& operator=(const ClapTrap &other);
		~ClapTrap();

		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};

#endif