/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcauchet <jcauchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 11:13:53 by jcauchet          #+#    #+#             */
/*   Updated: 2022/10/06 10:30:46y jcauchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"
bool bsp(Point const a, Point const b, Point const c, Point const point);

int main()
{
	{
		Point A(0, 0);
		Point B(0, 30);
		Point C(20, 30);
		Point P(10, 30);

		if (bsp(A, B, C, P))
			std::cout << "Inside\n";
		else
			std::cout << "Outside\n";
	}
	{
		Point A(0, 0);
		Point B(10, 30);
		Point C(20, 0);
		Point P(10, 15);

		if (bsp(A, B, C, P))
			std::cout << "Inside\n";
		else
			std::cout << "Outside\n";
	}
	{
		Point A(0, 0);
		Point B(10, 30);
		Point C(20, 0);
		Point P(30, 15);

		if (bsp(A, B, C, P))
			std::cout << "Inside\n";
		else
			std::cout << "Outside\n";	
	}
}
