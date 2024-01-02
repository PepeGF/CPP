/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcauchet <jcauchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 10:01:10 by jcauchet          #+#    #+#             */
/*   Updated: 2022/10/10 10:02:55y jcauchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
	this->type = "Dog";
	std::cout << "Dog: constructor called" << std::endl;
}

Dog::Dog(Dog const &src)
{
	std::cout << "Dog: copy constructor called" << std::endl;
	*this = src;
}

Dog &Dog::operator=(Dog const &rhs)
{
	Animal::operator=(rhs);
	return *this;
}

Dog::~Dog()
{
	std::cout << "Dog: destructor called" << std::endl;
}

void	Dog::makeSound() const
{
	std::cout << "Wouf Wouf" << std::endl;
}

std::string	Dog::getType() const
{
	return this->type;
}
