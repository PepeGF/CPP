/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcauchet <jcauchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 10:56:28 by jcauchet          #+#    #+#             */
/*   Updated: 2022/10/05 11:42:41y jcauchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _i(0)
{
	// std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int const val)
{
	// std::cout << "Int constructor called" << std::endl;
	if (val << this->_d <= 2147483647 && val << this->_d >= -2147483648)
		this->_i = val << this->_d;
}

Fixed::Fixed(float const val)
{
	// std::cout << "Float constructor called" << std::endl;
	this->_i = int(roundf(val * (1 << this->_d)));
}

Fixed::Fixed(Fixed const &src)
{
	// std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

// Bits

int	Fixed::getRawBits() const
{
	return this->_i;
}

void Fixed::setRawBits(int const raw)
{
	this->_i = (raw <= 2147483647 && raw >= -2147483648) ? raw : 0;
}

// Transform

float	Fixed::toFloat() const
{
	return ((float)((float)this->_i / (float)(1 << this->_d)));
}

int	Fixed::toInt() const
{
	return (this->_i / (1 << this->_d));
}

std::ostream &operator<<(std::ostream &o, Fixed const &obj)
{
	o << obj.toFloat();
	return o;
}

// Operations

Fixed &Fixed::operator=(Fixed const &rhs)
{
	// std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs)
		this->_i = rhs.getRawBits();
	return *this;
}

Fixed &Fixed::operator+(Fixed const &rhs)
{
	if (this->_i + rhs.getRawBits() <= 2147483647)
		this->_i += rhs.getRawBits();
	return *this;	
}

Fixed &Fixed::operator-(Fixed const &rhs)
{
	if (this->_i - rhs.getRawBits() >= -2147483648)
		this->_i -= rhs.getRawBits();
	return *this;	
}

Fixed &Fixed::operator*(Fixed const &rhs)
{
	if (rhs.getRawBits() != 0)
	{
		this->_i = this->getRawBits() * rhs.getRawBits();
		this->_i = this->_i >> this->_d;
	}
	else
		this->_i = 0;
	return *this;	
}

Fixed &Fixed::operator/(Fixed const &rhs)
{
	if (rhs.getRawBits() != 0)
	{
		this->_i = this->getRawBits() / rhs.getRawBits();
		this->_i = this->_i << this->_d;
	}
	else
		this->_i = 0;
	return *this;	
}

Fixed &Fixed::operator--()
{
	if (this->_i != -2147483648)
		--this->_i;
	return *this;	
}

Fixed &Fixed::operator++()
{
	if (this->_i != 2147483647)
		++this->_i;
	return *this;	
}

Fixed Fixed::operator--(int)
{
	Fixed copy(*this);
	if (this->_i != -2147483648)
		this->_i--;
	return copy;	
}

Fixed Fixed::operator++(int)
{
	Fixed copy(*this);
	if (this->_i != 2147483647)
		this->_i++;
	return copy;	
}

// Compare

Fixed const &Fixed::min(Fixed const &o1, Fixed const &o2)
{
	if (Fixed(o1) <= Fixed(o2))
		return o1;
	else
		return o2;
}

Fixed &Fixed::min(Fixed &o1, Fixed &o2)
{
	if (o1 <= o2)
		return o1;
	else
		return o2;
}

Fixed const &Fixed::max(Fixed const &o1, Fixed const &o2)
{
	if (Fixed(o1) >= Fixed(o2))
		return o1;
	else
		return o2;
}

Fixed &Fixed::max(Fixed &o1, Fixed &o2)
{
	if (o1 >= o2)
		return o1;
	else
		return o2;
}

bool Fixed::operator<(Fixed const &obj)
{
	return this->_i < obj._i;
}

bool Fixed::operator>(Fixed const &obj)
{
	return this->_i > obj._i;
}

bool Fixed::operator<=(Fixed const &obj)
{
	return this->_i <= obj._i;
}

bool Fixed::operator>=(Fixed const &obj)
{
	return this->_i >= obj._i;
}

bool Fixed::operator==(Fixed const &obj)
{
	return this->_i == obj._i;
}

bool Fixed::operator!=(Fixed const &obj)
{
	return this->_i != obj._i;
}

Fixed::~Fixed ()
{
	// std::cout << "Destructor called" << std::endl;
}
