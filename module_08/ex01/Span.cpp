#include "Span.hpp"
#include <limits>

Span::Span(unsigned int N) : _size(N) {
	_container.reserve(N);
}

Span::Span(const Span &other) : _size(other._size), _container(other._container){}

Span &Span::operator=(const Span &other) {
	if (this != &other){
		_size = other._size;
		_container = other._container;
	}
	return *this;
}

Span::~Span(){}

void Span::addNumber(int value){
	if(_container.size() >= _size){
		throw std::overflow_error("Container is full, can't add more numbers");
	}
	_container.push_back(value);
}

unsigned int Span::shortestSpan(){
	if (_container.size() < 2)
		throw std::logic_error("Not enough numbers to find a span.");
	std::vector<int> sortedCopy = _container;
	std::sort(sortedCopy.begin(), sortedCopy.end());
	long minSpan = std::numeric_limits<long>::max();
	for (size_t i = 0; i < sortedCopy.size() - 1; i++) {
		long span = static_cast<long>(sortedCopy[i + 1]) - sortedCopy[i];
		if (span < minSpan)
			minSpan = span;
	}
	return minSpan;
	
}

unsigned int Span::longestSpan(){
	if (_container.size() < 2)
		throw std::logic_error("Not enough numbers to find a span.");
	int minValue = *std::min_element(_container.begin(), _container.end());
	int maxValue = *std::max_element(_container.begin(), _container.end());
	long diff = static_cast<long>(maxValue) - minValue;
	return diff;

}
