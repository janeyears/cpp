#include "Brain.hpp"

Brain::Brain(){
	std::cout << "🧠 Brain default constructor has been called" << std::endl;
}

Brain::Brain(const Brain &other){
	*this = other;
	std::cout << "🧠 Brain copy constructor has been called" << std::endl;
}

Brain& Brain::operator=(const Brain &other) {
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = other._ideas[i];
	std::cout << "🧠 Brain assignment operator has been called" << std::endl;
	return *this;
}

Brain::~Brain(){
	std::cout << "🧠 Brain destructor has been called" << std::endl;
}

std::string Brain::getIdea(unsigned int i) const {
	if (i > 99) {
		std::cout << "Idea index is too high, animals can't have so many ideas. Try from 0 to 99" << std::endl;
		return (NULL);
	}
	else
		return this->_ideas[i];
}

void Brain::setIdea(unsigned int i, std::string idea) {
	if (i > 99) {
		std::cout << "Idea index is too high, animals can't have so many ideas. Try from 0 to 99" << std::endl;
		return;
	}
	else
		this->_ideas[i] = idea;
}