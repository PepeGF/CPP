/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcauchet <jcauchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 10:21:01 by jcauchet          #+#    #+#             */
/*   Updated: 2022/10/09 13:14:51y jcauchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	this->_name = "Unknown";
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << "FragTrap: Default constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	this->_name = name;
	std::cout << "FragTrap: Constructor with name called" << std::endl;
}

FragTrap::FragTrap(FragTrap const &src)
{
	std::cout << "FragTrap: Copy constructor called" << std::endl;
	*this = src;
}

FragTrap &FragTrap::operator=(FragTrap const &rhs)
{
	ClapTrap::operator=(rhs);
	return *this;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap: Default destructor called" << std::endl;
}

void	FragTrap::attack(const std::string target)
{
	std::cout << "FragTrap ";
	if (this->_energyPoints > 0 && this->_hitPoints > 0)
	{
		std::cout << this->_name << " attacks " << target << ", causing ";
		std::cout << this->_attackDamage << " points of damage!" << std::endl;
		this->_energyPoints--;
	}
	else
		std::cout << this->_name << " couldn't attack!" << std::endl;
}

void	FragTrap::highFivesGuys()
{
	std::cout << this->getName() << ": give me high fives!" << std::endl;
}
