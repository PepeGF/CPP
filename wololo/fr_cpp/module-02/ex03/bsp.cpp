/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcauchet <jcauchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 14:05:05 by jcauchet          #+#    #+#             */
/*   Updated: 2022/10/07 12:09:40 by jcauchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "Fixed.hpp"

float area(Point const a, Point const b, Point const c)
{
	float ret((a.getX() * (b.getY() - c.getY()) + b.getX() * (c.getY() - a.getY()) + c.getX() * (a.getY() - b.getY())) / 2.0);
	if (ret < 0)
		ret = -ret;
	return ret;
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	float ABC = area(a, b, c);
	float PBC = area(point, b, c);
	float APC = area(a, point, c);
	float ABP = area(a, b, point);

	if (!PBC || !APC || !ABP)
		return false;
	return (ABC == PBC + APC + ABP);
}