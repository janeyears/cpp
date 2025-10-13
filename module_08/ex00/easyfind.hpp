#pragma once
#include <algorithm>

template<typename T>
typename T::iterator easyfind(T &container, int value){
	typename T::iterator i;
	i = std::find(container.begin(), container.end(), value);
	if (i == container.end())
		throw std::runtime_error("Value not found in this container");
	else
		return i;
}