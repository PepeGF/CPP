/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcauchet <jcauchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 12:18:20 by jcauchet          #+#    #+#             */
/*   Updated: 2022/10/06 17:48:18y jcauchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "Fixed.hpp"

Point::Point() : _x(0), _y(0) {}

Point &Point::operator=(Point const &rhs)
{
	if (this != &rhs)
	{
		const_cast<Fixed &>(this->_x) = rhs._x;
		const_cast<Fixed &>(this->_y) = rhs._y;
	}
	return *this;
}

Point::Point (float const i, float const j) : _x(i), _y(j) {}

Point::Point(Point const &src)
{
	*this = src;
}

float	Point::getX() const
{
	return (this->_x.toFloat());
}

float	Point::getY() const
{
	return (this->_y.toFloat());
}

Point::~Point() {}
