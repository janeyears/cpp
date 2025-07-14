#include "ScavTrap.hpp"

int main() {
	std::cout << "Creating ScavTrap" << std::endl;
	ScavTrap scav1("SC4V-TP");

	scav1.attack("Skag");
	scav1.guardGate();

	std::cout << "\nTesting copy constructor" << std::endl;
	ScavTrap scav3(scav1);

	std::cout << "\nTesting copy assignment" << std::endl;
	ScavTrap scav4;
	scav4 = scav1;

	std::cout << "\nNow destroy all of them" << std::endl;
	return 0;
	}