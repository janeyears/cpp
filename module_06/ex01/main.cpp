#include "Serializer.hpp"

int main(){
	
	int x = 123;
	int* ptr = &x;

	// Convert pointer → integer
	uintptr_t raw = reinterpret_cast<uintptr_t>(ptr);

	// Convert integer → pointer
	int* newPtr = reinterpret_cast<int*>(raw);

	std::cout << "Original pointer: " << ptr << "\n";
	std::cout << "Raw integer: " << raw << "\n";
	std::cout << "Restored pointer: " << newPtr << "\n";
}