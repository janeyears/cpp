#include "PmergeMe.hpp"

PmergeMe::PmergeMe(const std::vector<unsigned int> &input)
	: _vector(input), _deque(input.begin(), input.end()), timeV(0), timeD(0) {}

PmergeMe::PmergeMe(const PmergeMe &other)
	: _vector(other._vector),
	  _deque(other._deque),
	  timeV(other.timeV),
	  timeD(other.timeD) {}

PmergeMe &PmergeMe::operator=(const PmergeMe &other) {
	if (this != &other) { 
		_vector = other._vector;
		_deque = other._deque;
		timeV = other.timeV;
		timeD = other.timeD;
	}
	return *this;
}

PmergeMe::~PmergeMe(){}

void PmergeMe::sortContainers() {
	timeV = timeVector();
	timeD = timeDeque();
	printResults();
}

double PmergeMe::timeVector() {
	auto start = std::chrono::high_resolution_clock::now();
	sortVector();
	auto end = std::chrono::high_resolution_clock::now();
	return std::chrono::duration<double, std::micro>(end - start).count();
}

double PmergeMe::timeDeque() {
	auto start = std::chrono::high_resolution_clock::now();
	sortDeque();
	auto end = std::chrono::high_resolution_clock::now();
	return std::chrono::duration<double, std::micro>(end - start).count();
}

void PmergeMe::printResults() {
	std::cout << "Before: ";
	for (size_t i = 0; i < _vector.size(); ++i)
		std::cout << _vector[i] << " ";
	std::cout << std::endl;

	std::cout << "After: ";
	for (size_t i = 0; i < _vector.size(); ++i)
		std::cout << _vector[i] << " ";
	std::cout << std::endl;

	std::cout << "Time to process a range of " << _vector.size()
			<< " elements with std::vector : " << timeV << " us" << std::endl;
	std::cout << "Time to process a range of " << _deque.size()
			<< " elements with std::deque  : " << timeD << " us" << std::endl;
}

