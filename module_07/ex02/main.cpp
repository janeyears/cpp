#include "Array.hpp"

int main() {
	try {
		std::cout << "=== Test 1: Default constructor ===\n";
		Array<int> a;
		std::cout << "Size of a: " << a.size() << "\n";

		std::cout << "\n=== Test 2: Constructor with size ===\n";
		Array<int> b(5);
		std::cout << "Size of b: " << b.size() << "\n";
		for (unsigned int i = 0; i < b.size(); i++)
			std::cout << "b[" << i << "] = " << b[i] << "\n";

		std::cout << "\n=== Test 3: Modify elements ===\n";
		for (unsigned int i = 0; i < b.size(); i++)
			b[i] = i * 10;
		for (unsigned int i = 0; i < b.size(); i++)
			std::cout << "b[" << i << "] = " << b[i] << "\n";

		std::cout << "\n=== Test 4: Out of bounds access ===\n";
		try {
			std::cout << b[10] << "\n"; // should throw
		} catch (const std::exception& e) {
			std::cerr << "Exception caught: " << e.what() << "\n";
		}

		std::cout << "\n=== Test 5: Array of strings ===\n";
		Array<std::string> s(3);
		s[0] = "Hello";
		s[1] = "World";
		s[2] = "!";
		for (unsigned int i = 0; i < s.size(); i++)
			std::cout << s[i] << " ";
		std::cout << "\n";

	} catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << "\n";
	}

	return 0;
}
