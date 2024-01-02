/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcauchet <jcauchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 10:08:11 by jcauchet          #+#    #+#             */
/*   Updated: 2022/10/10 16:02:25 by jcauchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
	this->type = "Cat";
	std::cout << "Cat: constructor called" << std::endl;
	this->_brain = new Brain();
}

Cat::Cat(Cat const &src)
{
	std::cout << "Cat: copy constructor called" << std::endl;
	this->type = src.type;
	this->_brain = new Brain();
	*this->_brain = *src._brain;
}

Cat &Cat::operator=(Cat const &rhs)
{
	Animal::operator=(rhs);
	return *this;
}

Cat::~Cat()
{
	delete this->_brain;
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
