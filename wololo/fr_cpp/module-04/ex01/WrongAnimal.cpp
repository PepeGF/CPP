/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongWrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcauchet <jcauchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 09:47:46 by jcauchet          #+#    #+#             */
/*   Updated: 2022/10/10 11:14:39 by jcauchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	this->type = "WrongAnimal";
	std::cout << "WrongAnimal: constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const &src)
{
	std::cout << "WrongAnimal: copy constructor called" << std::endl;
	*this = src;
}

WrongAnimal &WrongAnimal::operator=(WrongAnimal const &rhs)
{
	if (this != &rhs)
		this->type = rhs.type;
	return *this;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal: destructor called" << std::endl;
}

void	WrongAnimal::makeSound() const
{
	std::cout << "**WrongAnimal sound**" << std::endl;
}

std::string	WrongAnimal::getType() const
{
	return this->type;
}
