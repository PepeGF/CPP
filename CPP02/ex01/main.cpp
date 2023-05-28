#include "Fixed.hpp"
#include <iostream>

int main()
{
	// Fixed a;
	Fixed const b( 10 );
	Fixed const c( 42.001f );
	std::cout << c.getRawBits() << std::endl;

	Fixed const d( 42.010f );
	std::cout << d.getRawBits() << std::endl;

	Fixed const e( 42.100f );
	std::cout << e.getRawBits() << std::endl;

	Fixed const f( 42.1f );
	std::cout << f.getRawBits() << std::endl;

	Fixed const g( 42.5f );
	std::cout << g.getRawBits() << std::endl;
	// Fixed const d( b );

	// std::cout << c.toInt() << std::endl;
	// a = Fixed( 1234.4321f );

	// std::cout << "a is " << a << std::endl;
	// std::cout << "b is " << b << std::endl;
	// std::cout << "c is " << c << std::endl;
	// std::cout << "d is " << d << std::endl;

	// std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	// std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	// std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	// std::cout << "d is " << d.toInt() << " as integer" << std::endl;
	// std::cout << "b is " << b.toFloat() << " as float" << std::endl;
	// std::cout << "b is " << c.toInt() << " as integer" << std::endl;
	// std::cout << "b is " << c.toFloat() << " as float" << std::endl;
	
	return 0;
}
