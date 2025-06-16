#include "Zombie.hpp"

Zombie* newZombie(std::string name);
void randomChump(std::string name);

int main() {
	Zombie zombie1("Alex");
	zombie1.announce();

	Zombie* zombie2 = newZombie("Felix");
	zombie2->announce();

	randomChump("Bob");
	
	delete zombie2;

	return 0;
	
}