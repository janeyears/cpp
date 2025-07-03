#include "ClapTrap.hpp"

int main(){
	ClapTrap ct1;
	ClapTrap ct2("Robert");

	ct1.attack("Skag");
	ct2.takeDamage(5);
	ct2.takeDamage(4);
	ct2.beRepaired(3);
	ct1.takeDamage(10);
	ct1.attack("Skag");
	ct1.beRepaired(10);
	return 1;
}