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
	printBefore();
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

void PmergeMe::printBefore(){
	std::cout << "Before: ";
	for (size_t i = 0; i < _vector.size(); ++i)
		std::cout << _vector[i] << " ";
	std::cout << std::endl;
}

void PmergeMe::printResults() {
	std::cout << "After: ";
	for (size_t i = 0; i < _vector.size(); ++i)
		std::cout << _vector[i] << " ";
	std::cout << std::endl;

	std::cout << "Time to process a range of " << _vector.size()
			<< " elements with std::vector : " << timeV << " us" << std::endl;
	std::cout << "Time to process a range of " << _deque.size()
			<< " elements with std::deque  : " << timeD << " us" << std::endl;
}

// DEQUE SORTING

void PmergeMe::sortDeque() {
	createAndSortPairsDeque();
	separateSmallestDeque();
	recursiveSortLargestDeque();
	insertSmallestBackDeque();
	addLeftoversDeque();
}

void PmergeMe::createAndSortPairsDeque() {
	_pairsDeque.clear();

	for (size_t i = 0; i + 1 < _deque.size(); i += 2) {
		unsigned int a = _deque[i];
		unsigned int b = _deque[i + 1];
		if (a > b)
			std::swap(a, b);
		_pairsDeque.push_back(std::make_pair(a, b));
	}

	if (_deque.size() % 2 != 0)
		_leftoverDeque = _deque.back();
}

void PmergeMe::separateSmallestDeque() {
	_mainDeque.clear();
	_pendDeque.clear();

	for (size_t i = 0; i < _pairsDeque.size(); ++i) {
		_pendDeque.push_back(_pairsDeque[i].first);
		_mainDeque.push_back(_pairsDeque[i].second);
	}
}

void PmergeMe::recursiveSortLargestDeque() {
	if (_mainDeque.size() <= 1)
		return;

	std::sort(_mainDeque.begin(), _mainDeque.end());
}

void PmergeMe::insertSmallestBackDeque() {
	if (!_pendDeque.empty())
		_mainDeque.insert(_mainDeque.begin(), _pendDeque[0]);

	for (size_t i = 1; i < _pendDeque.size(); ++i) {
		unsigned int val = _pendDeque[i];
		std::deque<unsigned int>::iterator pos =
			std::lower_bound(_mainDeque.begin(), _mainDeque.end(), val);
		_mainDeque.insert(pos, val);
	}
}

void PmergeMe::addLeftoversDeque() {
	if (_deque.size() % 2 != 0) {
		unsigned int val = _leftoverDeque;
		std::deque<unsigned int>::iterator pos =
			std::lower_bound(_mainDeque.begin(), _mainDeque.end(), val);
		_mainDeque.insert(pos, val);
	}

	_deque = _mainDeque;
}


// VECTOR SORTING

void PmergeMe::sortVector() {
	createAndSortPairsVector();
	separateSmallestVector();
	recursiveSortLargestVector();
	insertSmallestBackVector();
	addLeftoversVector();
}

void PmergeMe::createAndSortPairsVector() {
	_pairsVector.clear();

	for (size_t i = 0; i + 1 < _vector.size(); i += 2) {
		unsigned int a = _vector[i];
		unsigned int b = _vector[i + 1];
		if (a > b)
			std::swap(a, b);
		_pairsVector.push_back(std::make_pair(a, b));
	}

	// Handle leftover element if odd count
	if (_vector.size() % 2 != 0)
		_leftoverVector = _vector.back();
}

void PmergeMe::separateSmallestVector() {
	_mainVector.clear();
	_pendVector.clear();

	for (size_t i = 0; i < _pairsVector.size(); ++i) {
		_pendVector.push_back(_pairsVector[i].first);  // smaller
		_mainVector.push_back(_pairsVector[i].second); // larger
	}
}

void PmergeMe::recursiveSortLargestVector() {
	if (_mainVector.size() <= 1)
		return;

	// Recursively apply the same logic (or just use std::sort for simplicity)
	std::sort(_mainVector.begin(), _mainVector.end());
}


void PmergeMe::insertSmallestBackVector() {
	// The first element of _pendVector is always smaller than first element of the main
	// So i just insert it manually at the beginning
	if (!_pendVector.empty())
		_mainVector.insert(_mainVector.begin(), _pendVector[0]);

	for (size_t i = 1; i < _pendVector.size(); ++i) {
		unsigned int val = _pendVector[i];
		std::vector<unsigned int>::iterator pos = std::lower_bound(_mainVector.begin(), _mainVector.end(), val);
		_mainVector.insert(pos, val);
	}
}

void PmergeMe::addLeftoversVector() {
	if (_vector.size() % 2 != 0) {
		unsigned int val = _leftoverVector;
		std::vector<unsigned int>::iterator pos = std::lower_bound(_mainVector.begin(), _mainVector.end(), val);
		_mainVector.insert(pos, val);
	}

	_vector = _mainVector;
}