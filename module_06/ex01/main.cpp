#include "Serializer.hpp"

int main() {
	Data data;
	data.value = 42;
	data.name = "Evgeniia";

	// serialize
	uintptr_t raw = Serializer::serialize(&data);
	std::cout << "Serialized value: " << raw << std::endl;

	// deserialize
	Data* deserialized = Serializer::deserialize(raw);

	std::cout << "Deserialized Data address: " << deserialized << std::endl;
	std::cout << "Deserialized Data value: " << deserialized->value << std::endl;
	std::cout << "Deserialized Data name: " << deserialized->name << std::endl;

	if (deserialized == &data)
		std::cout << "The data was correctly serialized and deserialized" << std::endl;
	else
		std::cout << "Error" << std::endl;

	return 0;
}
