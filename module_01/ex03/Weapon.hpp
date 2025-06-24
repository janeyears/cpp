#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iomanip>
#include "iostream"

class Weapon {
	private:
		std::string _type;
	public:
		Weapon();
		~Weapon();
		Weapon(std::string type);
		const std::string& getType();
		void setType(std::string newType);
};
#endif