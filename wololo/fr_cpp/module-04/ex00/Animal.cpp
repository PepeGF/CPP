/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcauchet <jcauchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 09:47:46 by jcauchet          #+#    #+#             */
/*   Updated: 2022/10/10 10:22:47 by jcauchet         ###   ########.fr       */
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

void	Animal::makeSound() const
{
	std::cout << "**Animal sound**" << std::endl;
}

std::string	Animal::getType() const
{
	return this->type;
}
