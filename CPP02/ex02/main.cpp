#include "Fixed.hpp"
#include <iostream>

int main()
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << b << std::endl;

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;


	std::cout << Fixed::max( a, b ) << std::endl;
	
	return 0;
}
