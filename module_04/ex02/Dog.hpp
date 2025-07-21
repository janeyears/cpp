#ifndef DOG_HPP
#define DOG_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal {
	public:
		Dog();
		Dog(std::string type);
		Dog(const Dog &other);
		Dog& operator=(const Dog &other);
		~Dog();
		void makeSound(void) const override;
		Brain* getBrain() const;
	private:
		Brain *_brain;
};

#endif