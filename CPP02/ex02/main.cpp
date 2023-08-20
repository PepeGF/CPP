#include "Fixed.hpp"
#include <iostream>

int main()
{
//	std::cout << 387.42/8.21 << std::endl << "-----------------" << std::endl;
//	Fixed wololo(387.42f);
//	Fixed mierda(8.21f);
//	Fixed otro(wololo/mierda);
//	std::cout <<"otro: " << otro << std::endl;

	Fixed z(3.256f);
	Fixed y;

	y = z++;
	std::cout << "y: " << y << " z: " << z << std::endl;
//	Fixed a;
//	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
//	std::cout << b << std::endl;

//	std::cout << a << std::endl;
//	std::cout << ++a << std::endl;
//	std::cout << a << std::endl;
//	std::cout << a++ << std::endl;
//	std::cout << a << std::endl;


//	std::cout << Fixed::max( a, b ) << std::endl;
	
	return 0;
}
