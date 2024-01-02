/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliencaucheteux <juliencaucheteux@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 09:47:46 by jcauchet          #+#    #+#             */
/*   Updated: 2022/10/10 20:06:15 by juliencauch      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
	this->type = "Animal";
	std::cout << "Animal: constructor called" << std::endl;
}

Animal::Animal(Animal const &src)
{
	std::cout << "Animal: copy constructor called" << std::endl;
	*this = src;
}

Animal &Animal::operator=(Animal const &rhs)
{
	if (this != &rhs)
		this->type = rhs.type;
	return *this;
}

Animal::~Animal()
{
	std::cout << "Animal: destructor called" << std::endl;
}

std::string	Animal::getType() const
{
	return this->type;
}
