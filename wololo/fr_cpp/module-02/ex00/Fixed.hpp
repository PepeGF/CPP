/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcauchet <jcauchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 10:53:47 by jcauchet          #+#    #+#             */
/*   Updated: 2022/10/05 14:03:10 by jcauchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

class Fixed
{
public:
	Fixed(); // Normal constructor
	Fixed(Fixed const &src); // Copy constructor
	Fixed &operator=(Fixed const &rhs); // Affectation operator
	~Fixed(); // Normal destructor
	
	int		getRawBits() const;
	void	setRawBits(int const raw);
private:
	int	_i;
	static int const _d = 8;
};
