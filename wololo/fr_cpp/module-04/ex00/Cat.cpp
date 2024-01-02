/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcauchet <jcauchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 10:08:11 by jcauchet          #+#    #+#             */
/*   Updated: 2022/10/10 11:19:21 by jcauchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
	this->type = "Cat";
	std::cout << "Cat: constructor called" << std::endl;
}

Cat::Cat(Cat const &src)
{
	std::cout << "Cat: copy constructor called" << std::endl;
	*this = src;
}

Cat &Cat::operator=(Cat const &rhs)
{
	Animal::operator=(rhs);
	return *this;
}

Cat::~Cat()
{
	std::cout << "Cat: destructor called" << std::endl;
}

void	Cat::makeSound() const
{
	std::cout << "Miaou miaou" << std::endl;
}

std::string	Cat::getType() const
{
	return this->type;
}
