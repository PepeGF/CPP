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
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int const val)
{
	std::cout << "Int constructor called" << std::endl;
	this->_i = val << this->_d;
}

Fixed::Fixed(float const val)
{
	std::cout << "Float constructor called" << std::endl;
	this->_i = int(roundf(val * (1 << this->_d)));
}

Fixed::Fixed(Fixed const &src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

int	Fixed::getRawBits() const
{
	return this->_i;
}

void Fixed::setRawBits(int const raw)
{
	this->_i = raw;
}

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

Fixed &Fixed::operator=(Fixed const &rhs)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs)
		this->_i = rhs.getRawBits();
	return *this;
}

Fixed::~Fixed ()
{
	std::cout << "Destructor called" << std::endl;
}
