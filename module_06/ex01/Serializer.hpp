#pragma once
#include <iostream>
#include <cstdint>

struct Data
{
	int value;
	std::string name;
};

class Serializer {
	public:
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
	private:
		Serializer();
		Serializer(Serializer &other) = delete;
		Serializer &operator=(Serializer &other) = delete;
		~Serializer();
};