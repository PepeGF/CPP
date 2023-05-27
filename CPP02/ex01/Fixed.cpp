#include "Fixed.hpp"

Fixed::Fixed(int integer)
{
	this->_value = integer;
	this->_value << this->_bits;
}

Fixed::Fixed(const Fixed &source) : _value(source._value)
{
	std::cout << "Copy constructor called" << std::endl;
}

Fixed::Fixed() : _value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed &other)
{
	std::cout << "Assignation operator called" << std::endl;
	if (this != &other)
		this->_value = other.getRawBits();
	return (*this);
}

int	Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_value);
}

void	Fixed::setRawBits(int const raw)
{
	this->_value = raw;
}
