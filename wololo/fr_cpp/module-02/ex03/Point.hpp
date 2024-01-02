/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcauchet <jcauchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 12:05:04 by jcauchet          #+#    #+#             */
/*   Updated: 2022/10/06 19:01:51 by jcauchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Fixed.hpp"

class Point
{
public:
	Point();
	Point (Point const &src);
	Point (float const i, float const j);
	Point &operator=(Point const &rhs);
	~Point();

	float	getX() const;
	float	getY() const;
private:
	Fixed const _x;
	Fixed const _y;
};
