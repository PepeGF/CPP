/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliencaucheteux <juliencaucheteux@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 10:53:47 by jcauchet          #+#    #+#             */
/*   Updated: 2022/10/06 00:07:56 by juliencauch      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <cmath>

class Fixed
{
public:
	Fixed(); // Normal constructor
	Fixed(int const val);
	Fixed(float const val);
	Fixed(Fixed const &src); // Copy constructor
	Fixed &operator=(Fixed const &rhs); // Affectation operator
	Fixed &operator+(Fixed const &rhs);
	Fixed &operator-(Fixed const &rhs);
	Fixed &operator*(Fixed const &rhs);
	Fixed &operator/(Fixed const &rhs);
	Fixed &operator++();
	Fixed operator++(int val);
	Fixed &operator--();
	Fixed operator--(int val);

	bool operator<(Fixed const &obj);
	bool operator>(Fixed const &obj);
	bool operator>=(Fixed const &obj);
	bool operator<=(Fixed const &obj);
	bool operator==(Fixed const &obj);
	bool operator!=(Fixed const &obj);

	static Fixed const &min(Fixed const &o1, Fixed const &o2);
	static Fixed &min(Fixed &o1, Fixed &o2);
	static Fixed const &max(Fixed const &o1, Fixed const &o2);
	static Fixed &max(Fixed &o1, Fixed &o2);
	~Fixed(); // Normal destructor
	
	int		getRawBits() const;
	void	setRawBits(int const raw);
	float	toFloat() const;
	int		toInt() const;
private:
	int	_i;
	static int const _d = 8;
};

std::ostream &operator<<(std::ostream &o, Fixed const &obj);
