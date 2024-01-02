/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcauchet <jcauchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 18:19:11 by jcauchet          #+#    #+#             */
/*   Updated: 2022/10/12 11:25:21 by jcauchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "AMateria.hpp"

Ice::Ice() : AMateria("ice") {}

Ice::Ice(Ice const &src) : AMateria()
{
	*this = src;
}

Ice	&Ice::operator=(Ice const &rhs)
{
	if (this != &rhs)
		this->type = rhs.type;
	return *this;
}

Ice::~Ice() {}

AMateria *Ice::clone() const
{
	Ice *dup = new Ice();
	
	return dup;
}

void Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
