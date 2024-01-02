/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcauchet <jcauchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 11:13:53 by jcauchet          #+#    #+#             */
/*   Updated: 2022/10/05 14:02:58 by jcauchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main(void)
{
	{
		std::cout << "---------42 Main----------" << std::endl;
		Fixed a;
		Fixed b(a);
		Fixed c;
		c = b;
		std::cout << a.getRawBits() << std::endl;
		std::cout << b.getRawBits() << std::endl;
		std::cout << c.getRawBits() << std::endl;
	}
	// {
	// 	std::cout << std::endl << "---------My Main----------" << std::endl;
	// 	Fixed a;
	// 	a.setRawBits(42);
	// 	std::cout << a.getRawBits() << std::endl;
	// 	Fixed b(a);
	// 	std::cout << b.getRawBits() << std::endl;
	// 	Fixed c;
	// 	c = b;
	// 	std::cout << c.getRawBits() << std::endl;
	// }
}
