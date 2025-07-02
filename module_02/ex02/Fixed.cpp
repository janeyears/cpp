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

// Comparison operators

bool Fixed::operator>(const Fixed &other) const {
	return this->_value > other._value;
}

bool Fixed::operator<(const Fixed &other) const {
	return this->_value < other._value;
}

bool Fixed::operator>=(const Fixed &other) const {
	return this->_value >= other._value;
}

bool Fixed::operator<=(const Fixed &other) const {
	return this->_value <= other._value;
}

bool Fixed::operator==(const Fixed &other) const {
	return this->_value == other._value;
}

bool Fixed::operator!=(const Fixed &other) const {
	return this->_value != other._value;
}

//Arithmetic operators

Fixed Fixed::operator+(const Fixed &other) const {
	return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed &other) const {
	return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed &other) const {
	return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed &other) const {
	return Fixed(this->toFloat() / other.toFloat());
}

// Increment/decrement operators

Fixed &Fixed::operator++() {
	this->_value++;
	return *this;
}

Fixed Fixed::operator++(int) {
	Fixed temp(*this);
	this->_value++;
	return temp;
}

Fixed &Fixed::operator--() {
	this->_value--;
	return *this;
}

Fixed Fixed::operator--(int) {
	Fixed temp(*this);
	this->_value--;
	return temp;
}


Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	if (a < b)
		return (a);
	return (b);
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a < b)
		return (a);
	return (b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	if (a > b)
		return (a);
	return (b);	
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a > b)
		return (a);
	return (b);	
}