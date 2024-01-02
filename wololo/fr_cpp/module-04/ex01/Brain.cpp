/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliencaucheteux <juliencaucheteux@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 12:44:53 by jcauchet          #+#    #+#             */
/*   Updated: 2022/10/10 19:47:31 by juliencauch      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	for (int i = 0; i < 100; i++)
		this->ideas[i] = "Idea " + std::to_string(i);
	std::cout << "Brain: constructor called" << std::endl;
}

Brain::Brain(Brain const &src)
{
	std::cout << "Brain: copy constructor called" << std::endl;
	*this = src;
}

Brain &Brain::operator=(Brain const &rhs)
{
	if (this != &rhs)
		for (int i = 0; i < 100; i++)
			this->ideas[i] = rhs.ideas[i];
	return *this;
}

Brain::~Brain()
{
	std::cout << "Brain: destructor called" << std::endl;
}
