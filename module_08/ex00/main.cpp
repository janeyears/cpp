#include "easyfind.hpp"
#include <vector>
#include <list>
#include <iostream>

int main() {
	std::vector<int> v{10, 20, 30, 40, 50};
	std::list<int> l{5, 15, 25, 35};

	// Test with vector (found)
	try {
		auto it1 = easyfind(v, 30);
		std::cout << "Found in vector: " << *it1 << std::endl;
	} catch (const std::exception &e) {
		std::cerr << "❌ Vector test (30) failed: " << e.what() << std::endl;
	}

	// Test with list (found)
	try {
		auto it2 = easyfind(l, 25);
		std::cout << "Found in list: " << *it2 << std::endl;
	} catch (const std::exception &e) {
		std::cerr << "❌ List test (25) failed: " << e.what() << std::endl;
	}

	// Test with vector (not found)
	try {
		auto it3 = easyfind(v, 99);
		std::cout << "Found in vector: " << *it3 << std::endl;
	} catch (const std::exception &e) {
		std::cerr << "❌ Vector test (99) failed: " << e.what() << std::endl;
	}

	// Test with list (not found)
	try {
		auto it4 = easyfind(l, 99);
		std::cout << "Found in list: " << *it4 << std::endl;
	} catch (const std::exception &e) {
		std::cerr << "❌ List test (99) failed: " << e.what() << std::endl;
	}

	return 0;
}
