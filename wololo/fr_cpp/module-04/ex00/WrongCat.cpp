/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongWrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcauchet <jcauchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 11:16:32 by jcauchet          #+#    #+#             */
/*   Updated: 2022/10/10 11:18:47 by jcauchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	this->type = "WrongCat";
	std::cout << "WrongCat: constructor called" << std::endl;
}

WrongCat::WrongCat(WrongCat const &src)
{
	std::cout << "WrongCat: copy constructor called" << std::endl;
	*this = src;
}

WrongCat &WrongCat::operator=(WrongCat const &rhs)
{
	WrongAnimal::operator=(rhs);
	return *this;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat: destructor called" << std::endl;
}

void	WrongCat::makeSound() const
{
	std::cout << "Miaou Miaou" << std::endl;
}

std::string	WrongCat::getType() const
{
	return this->type;
}
