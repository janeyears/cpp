#pragma once
#include <vector>
#include <deque>
#include <iostream>

class PmergeMe {
	private:

		std::vector<unsigned int>	_vector;
		std::deque<unsigned int>	_deque;

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

		void printResults();


	public:
		PmergeMe(const std::vector<unsigned int> &input);
		PmergeMe(const PmergeMe &other);
		PmergeMe &operator=(const PmergeMe &other);
		~PmergeMe();

		void sortContainers();
};