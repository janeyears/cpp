#include "MutantStack.tpp"
#include <iostream>
#include <list>

int main() {
	std::cout << "=== Basic push/pop/top test ===" << std::endl;
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << "Top element: " << mstack.top() << std::endl; // 17
	mstack.pop();
	std::cout << "Size after pop: " << mstack.size() << std::endl; // 1

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	std::cout << "\n=== Forward iteration ===" << std::endl;
	for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it)
		std::cout << *it << std::endl;

	std::cout << "\n=== Reverse iteration ===" << std::endl;
	for (MutantStack<int>::reverse_iterator rit = mstack.rbegin(); rit != mstack.rend(); ++rit)
		std::cout << *rit << std::endl;

	std::cout << "\n=== Const iteration ===" << std::endl;
	const MutantStack<int> constStack = mstack;
	for (MutantStack<int>::const_iterator cit = constStack.begin(); cit != constStack.end(); ++cit)
		std::cout << *cit << std::endl;

	std::cout << "\n=== LIST TEST ===\n" << std::endl;

	std::list<int> lst;

	lst.push_back(5);
	lst.push_back(17);


	std::cout << "Last element: " << lst.back() << std::endl;
	lst.pop_back();
	std::cout << "Size after pop: " << lst.size() << std::endl;

	lst.push_back(3);
	lst.push_back(5);
	lst.push_back(737);
	lst.push_back(0);

	std::cout << "\n=== Forward iteration ===" << std::endl;
	for (std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it)
		std::cout << *it << std::endl;

	std::cout << "\n=== Reverse iteration ===" << std::endl;
	for (std::list<int>::reverse_iterator rit = lst.rbegin(); rit != lst.rend(); ++rit)
		std::cout << *rit << std::endl;


	std::cout << "\n=== Const iteration ===" << std::endl;
	const std::list<int> constLst = lst;
	for (std::list<int>::const_iterator cit = constLst.begin(); cit != constLst.end(); ++cit)
		std::cout << *cit << std::endl;

	return 0;
}