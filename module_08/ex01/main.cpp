#include "Span.hpp"
#include <iostream>
#include <list>

int main()
{

	try {
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	} catch (const std::exception &e){
		std::cerr << e.what() << std::endl;
	}

	try {
		Span sp(10000);

		// fill from vector
		std::vector<int> numbers = {1, 2, 3, 4, 5};
		sp.addRange(numbers.begin(), numbers.end());

		// fill from an array
		int arr[] = {10, 20, 30, 40};
		sp.addRange(std::begin(arr), std::end(arr));

		// fill from a list
		std::list<int> lst = {100, 200, 300};
		sp.addRange(lst.begin(), lst.end());

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	} catch (const std::exception &e){
		std::cerr << e.what() << std::endl;
	}
	try {
		Span sp = Span(1);
		sp.addNumber(6);
		sp.addNumber(3);
	} catch (const std::exception &e){
		std::cerr << e.what() << std::endl;
	}

	try {
		Span sp = Span(2);
		sp.addNumber(6);
		std::cout << sp.shortestSpan() << std::endl;
	} catch (const std::exception &e){
		std::cerr << e.what() << std::endl;
	}
	return 0;
}