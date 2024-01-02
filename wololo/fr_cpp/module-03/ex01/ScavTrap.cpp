/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcauchet <jcauchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 08:47:14 by jcauchet          #+#    #+#             */
/*   Updated: 2022/10/09 17:03:02 by jcauchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	this->_name = "Unknown";
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << "ScavTrap: Default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	this->_name = name;
	std::cout << "ScavTrap: Constructor with name called" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const &src)
{
	std::cout << "ScavTrap: Copy constructor called" << std::endl;
	*this = src;
}

ScavTrap &ScavTrap::operator=(ScavTrap const &rhs)
{
	ClapTrap::operator=(rhs);
	return *this;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap: Default destructor called" << std::endl;
}

void	ScavTrap::attack(const std::string target)
{
	std::cout << "ScavTrap ";
	if (this->_energyPoints > 0 && this->_hitPoints > 0)
	{
		std::cout << this->_name << " attacks " << target << ", causing ";
		std::cout << this->_attackDamage << " points of damage!" << std::endl;
		this->_energyPoints--;
	}
	else
		std::cout << this->_name << " couldn't attack!" << std::endl;
}

void	ScavTrap::guardGate()
{
	std::cout << this->getName() << " is now in Gate keeper mode" << std::endl;
}
