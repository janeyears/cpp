#include "iter.hpp"

int main(){
	int arrayInt[] = {0, 1, 2, 3};
	char arrayChar[] = {'a', 'b', 'c'};

	std::cout << "Original int array: ";
	iter(arrayInt, 4, print<int>);
	std::cout << "\nIncremented int array: ";
	iter(arrayInt, 4, increment<int>);
	iter(arrayInt, 4, print<int>);
	std::cout << std::endl;

	std::cout << "Original char array: ";
	iter(arrayChar, 3, print<char>);
	std::cout << "\nIncremented char array: ";
	iter(arrayChar, 3, increment<char>);
	iter(arrayChar, 3, print<char>);
	std::cout << std::endl;

}