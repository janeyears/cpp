#include "Array.hpp"

template <typename T>
Array<T>::Array() : _array(nullptr), _size(0){}

template <typename T>
Array<T>::Array(unsigned int n) : _array(nullptr), _size(n){
	if (n > 0)
		_array = new T[n]();
}

template <typename T>
Array<T>::Array(const Array &other) : _array(nullptr), _size(other._size){
	if (this->_size > 0){
		_array = new T[_size];
		for(unsigned int i = 0; i < _size; i++)
			_array[i] = other._array[i];
	}
}

template <typename T>
Array<T>& Array<T>::operator=(const Array &other){
	if (this != &other){
		delete[] this->_array;
		this->_size = other._size;
		this->_array = nullptr;
		if (this->_size > 0){
			_array = new T[_size];
			for(unsigned int i = 0; i < _size; i++)
				_array[i] = other._array[i];
		}
	}
	return *this;
}

template <typename T>
Array<T>::~Array() {
	delete[] _array;
}

template <typename T>
unsigned int Array<T>::size() const{
	return _size;
}

template <typename T>
T& Array<T>::operator[](unsigned int i) {
	if (i >= _size)
		throw std::out_of_range("Index out of bounds");
	return _array[i];
}

template <typename T>
const T& Array<T>::operator[](unsigned int i) const {
	if (i >= _size)
		throw std::out_of_range("Index out of bounds");
	return _array[i];
}