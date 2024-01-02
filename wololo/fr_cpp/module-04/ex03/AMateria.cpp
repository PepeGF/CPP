/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcauchet <jcauchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 09:26:57 by jcauchet          #+#    #+#             */
/*   Updated: 2022/10/12 11:26:09 by jcauchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria() : type("Unknown type") {}

AMateria::AMateria(AMateria const &src)
{
	*this = src;
}

AMateria	&AMateria::operator=(AMateria const &rhs)
{
	if (this != &rhs)
		this->type = rhs.type;
	return *this;
}

AMateria::~AMateria() {}

// Assignment functions and constructors

AMateria::AMateria(std::string const &type)
{
	this->type = type;
}

std::string const &AMateria::getType() const
{
	return this->type;
}

void AMateria::use(ICharacter &) {}
