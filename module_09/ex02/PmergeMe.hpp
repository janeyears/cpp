#pragma once
#include <vector>
#include <deque>
#include <iostream>

class PmergeMe {
	private:

		std::vector<unsigned int>	_vector;
		std::deque<unsigned int>	_deque;

		// For vector sorting
		std::vector<std::pair<unsigned int, unsigned int>> _pairsVector;
		std::vector<unsigned int> _mainVector;
		std::vector<unsigned int> _pendVector;
		unsigned int _leftoverVector = 0;

		// For deque sorting
		std::deque<std::pair<unsigned int, unsigned int>> _pairsDeque;
		std::deque<unsigned int> _mainDeque;
		std::deque<unsigned int> _pendDeque;
		unsigned int _leftoverDeque = 0;

		double	timeV;
		double	timeD;

		void sortVector();
		void sortDeque();

		void createAndSortPairsVector();
		void separateSmallestVector();
		void recursiveSortLargestVector();
		void insertSmallestBackVector();
		void addLeftoversVector();
		
		void createAndSortPairsDeque();
		void separateSmallestDeque();
		void recursiveSortLargestDeque();
		void insertSmallestBackDeque();
		void addLeftoversDeque();

		double	timeVector();
		double	timeDeque();

		void printBefore();
		void printResults();


	public:
		PmergeMe(const std::vector<unsigned int> &input);
		PmergeMe(const PmergeMe &other);
		PmergeMe &operator=(const PmergeMe &other);
		~PmergeMe();

		void sortContainers();
};