#include "iter.hpp"

int main(){
	int arrayInt[] = {0, 1, 2, 3};
	char arrayChar[] = {'a', 'b', 'c'};

	std::cout << "Original int array: ";
	iter(arrayInt, 4, print_element<int>);
	std::cout << "\nIncremented int array: ";
	iter(arrayInt, 4, increment<int>);
	iter(arrayInt, 4, print_element<int>);
	std::cout << std::endl;

	std::cout << "Original char array: ";
	iter(arrayChar, 3, print_element<char>);
	std::cout << "\nIncremented char array: ";
	iter(arrayChar, 3, increment<char>);
	iter(arrayChar, 3, print_element<char>);
	std::cout << std::endl;

	std::cout << "\nTest for nullptr array\n";

	try {
		int* nullArray = nullptr;
		iter(nullArray, 5, print_element<int>);
	} catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << "\n";
	}
	std::cout << "\nTest for zero  length\n";

	try {
		int arrayEmpty[] = {1, 2, 3};
		iter(arrayEmpty, 0, print_element<int>);
	} catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << "\n";
	}
}
