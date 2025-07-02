#include "Fixed.hpp"

int main( void ) {
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << a << std::endl; // 0
	std::cout << ++a << std::endl; // 0.00390625
	std::cout << a << std::endl; // 0.00390625
	std::cout << a++ << std::endl; // 0.00390625
	std::cout << a << std::endl; // 0.0078125
	std::cout << b << std::endl; // 10.1016
	std::cout << Fixed::max( a, b ) << std::endl; // 10.1016

	std::cout << --a << std::endl; // 0.00390625
	std::cout << a-- << std::endl; // 0.00390625
	std::cout << a << std::endl; // 0

	Fixed const c( Fixed( 5.05f ) + Fixed( 2 ) );
	std::cout << c << std::endl; // 7.05078

	Fixed const d( Fixed( 5.05f ) - Fixed( 2 ) );
	std::cout << d << std::endl; // 3.05078

	Fixed const f( Fixed( 5.05f ) / Fixed( 2 ) );
	std::cout << f << std::endl; // 2.52734

	std::cout << (c > d) << std::endl; // 1
	std::cout << (c < d) << std::endl; // 0
	std::cout << (c >= d) << std::endl; // 1
	std::cout << (c <= d) << std::endl; // 0
	std::cout << (c == d) << std::endl; // 0
	std::cout << (c != d) << std::endl; // 1
	std::cout << Fixed::min(c, d) << std::endl; // 3.05078

	const Fixed &minRef = Fixed::min(c, d); // 3.05078
	std::cout << minRef << std::endl;
	
	const Fixed &maxRef = Fixed::max(c, d); // 7.05078
	std::cout << maxRef << std::endl;

	return 0;
}