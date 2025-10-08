#pragma once
#include <stdexcept>
#include <iostream>


template <typename T>
class Array {
	public:
		Array();
		Array(unsigned int n);
		Array(const Array &other);
		Array &operator=(const Array &other);
		~Array();

		unsigned int size() const;

		T& operator[](unsigned int index);
		const T& operator[](unsigned int index) const;


	private:
		T *_array;
		unsigned int _size;
};

#include "Array.tpp"