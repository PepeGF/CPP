/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcauchet <jcauchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 10:53:47 by jcauchet          #+#    #+#             */
/*   Updated: 2022/10/05 14:24:40 by jcauchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
