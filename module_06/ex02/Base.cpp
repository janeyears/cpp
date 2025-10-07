#include "Base.hpp"
#include <iostream>


Base* generate(void){
	srand(time(NULL));
	int r = rand() % 3;
	switch (r) {
		case 0:
			return new A();
		case 1:
			return new B();
		case 2:
			return new C();
	}
	return NULL;
}

void identify(Base *p)
{
	 if (!p) {
		return;
	}
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
}

void identify(Base& p){
	try {
		(void)dynamic_cast<A&>(p);
		std::cout << "A\n";
		return;
	} catch (std::bad_cast&) {}

	try {
		(void)dynamic_cast<B&>(p);
		std::cout << "B\n";
		return;
	} catch (std::bad_cast&) {}

	try {
		(void)dynamic_cast<C&>(p);
		std::cout << "C\n";
		return;
	} catch (std::bad_cast&) {}
}