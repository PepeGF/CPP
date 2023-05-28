#include "Fixed.hpp"

Fixed::Fixed(int const integer)
{
	std::cout << "Int constructor called" << std::endl;
	this->_value = integer << this->_bits;
}

Fixed::Fixed(float const decimal)
{
	std::cout << "Float constructor called" << std::endl;
	this->_value = int(roundf(decimal * (1 << this->_bits)));
	std::cout << this->_value << std::endl;
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

int	Fixed::toInt() const
{
	return (this->_value >> this->_bits);
}

float	Fixed::toFloat() const
{
	return ((float)((float)(this->_value) / (float)(1 << this->_bits)));
}

std::ostream &operator<<(std::ostream &os, Fixed const &fix)
{
	os << fix.toFloat();
	return (os);
}

// http://orga.blog.unq.edu.ar/wp-content/uploads/sites/5/2018/05/orga_clase6_apuntePtoFijo.pdf