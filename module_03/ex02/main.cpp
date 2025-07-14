#include "FragTrap.hpp"

int main() {
    FragTrap frag("FR4G-TP");

    frag.attack("Skag");
    frag.highFivesGuys();

    FragTrap frag2(frag); // Copy constructor test
    FragTrap frag3;
    frag3 = frag; // Copy assignment test

    return 0;
}