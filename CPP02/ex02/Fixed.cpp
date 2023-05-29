#include "Fixed.hpp"

Fixed::Fixed() : _value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int const integer)
{
	std::cout << "Int constructor called" << std::endl;
	this->_value = integer << this->_bits;
}

Fixed::Fixed(float const decimal)
{
	std::cout << "Float constructor called" << std::endl;
	this->_value = int(roundf(decimal * (1 << this->_bits)));
	// std::cout << this->_value << std::endl;
}

Fixed::Fixed(Fixed const &source) : _value(source._value)
{
	std::cout << "Copy constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(Fixed const &fix)
{
	std::cout << "Assignation operator called" << std::endl;
	if (this != &fix)
		this->_value = fix.getRawBits();
	return (*this);
}

// https://es.wikibooks.org/wiki/Programaci%C3%B3n_en_C%2B%2B/Sobrecarga_de_Operadores

Fixed& Fixed::operator+(Fixed const &fix)
{
	this->_value += fix._value;
	return (*this);
}

Fixed& Fixed::operator-(Fixed const &fix)
{
	this->_value -= fix._value;
	return (*this);
}

Fixed& Fixed::operator*(Fixed const &fix)
{
	this->_value *= fix._value;
	this->_value = this->_value >> this->_bits;
	return (*this);
}

Fixed& Fixed::operator/(Fixed const &fix)
{
	if (fix._value != 0)
	{
		this->_value /= fix._value;
		this->_value = this->_value << this->_bits;
	}
	return (*this);
}

Fixed& Fixed::operator++()
{
	(this->_value)++;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed ret(*this);

	ret._value++;
	return (ret);
}

Fixed& Fixed::operator--()
{
	(this->_value)--;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed ret(*this);

	ret._value--;
	return (ret);
}

bool Fixed::operator>(Fixed const &rhs)
{
	return (this->_value > rhs._value);
}

bool Fixed::operator>=(Fixed const &rhs)
{
	return (this->_value >= rhs._value);
}

bool Fixed::operator<(Fixed const &rhs)
{
	return (this->_value < rhs._value);
}

bool Fixed::operator<=(Fixed const &rhs)
{
	return (this->_value <= rhs._value);
}

bool Fixed::operator==(Fixed const &rhs)
{
	return (this->_value == rhs._value);
}

bool Fixed::operator!=(Fixed const &rhs)
{
	return (this->_value != rhs._value);
}


Fixed const & Fixed::max(Fixed const &fix1, Fixed const &fix2)
{
	return ((Fixed)fix1 > (Fixed)fix2) ? fix1 : fix2;
}

Fixed& Fixed::max(Fixed &fix1, Fixed &fix2)
{
	return (fix1 > fix2) ? fix1 : fix2;
}

Fixed const & Fixed::min(Fixed const &fix1, Fixed const &fix2)
{
	return ((Fixed)fix1 < (Fixed)fix2) ? fix1 : fix2;
}

Fixed& Fixed::min(Fixed &fix1, Fixed &fix2)
{
	return (fix1 < fix2) ? fix1 : fix2;
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
	return ((float)((float)this->_value / (float)(1 << this->_bits)));
}

std::ostream& operator<<(std::ostream &os, Fixed const &fix)
{
	os << fix.toFloat();
	return (os);
}

// http://orga.blog.unq.edu.ar/wp-content/uploads/sites/5/2018/05/orga_clase6_apuntePtoFijo.pdf