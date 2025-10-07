#pragma once
#include <cstddef>
#include <iostream>

template<typename T, typename F>
void iter(T *array, size_t length, F func){
	if (array == nullptr || length == 0)
	{
		std::cout << "Array is empty or length is zero" << std::endl;
		return; 
	}
	for (size_t i = 0; i < length; i++)
	{
		func(array[i]);
	}
}

template<typename T>
void increment(T& element){
	++element;
}

template<typename T>
void print(T& element){
	std::cout << element << " ";
}