#include "Fixed.hpp"

Fixed::Fixed() {
	std::cout << "Default constructor called" << std::endl;
	this->_value = 0;
}

Fixed::Fixed(const int number) {
	std::cout << "Int constructor called" << std::endl;
	_value = number << _fractionalBits;
}

Fixed::Fixed(const float number) {
	std::cout << "Float constructor called" << std::endl;
	_value = roundf(number * (1 << _fractionalBits));
}

Fixed::Fixed(const Fixed &other) {
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed& Fixed::operator=(const Fixed &other) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other) {
		this->_value = other._value;
	}
	return *this;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return this->_value;
}
void Fixed::setRawBits(int const raw) {
	this->_value = raw;
}

float Fixed::toFloat(void) const {
	return (float)_value / (1 << _fractionalBits);
}

int Fixed::toInt(void) const {
	return _value >> _fractionalBits;
}
std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
	out << fixed.toFloat();
	return out;
}