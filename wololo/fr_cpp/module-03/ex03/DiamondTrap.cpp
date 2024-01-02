/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcauchet <jcauchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 10:38:23 by jcauchet          #+#    #+#             */
/*   Updated: 2022/10/09 17:53:13 by jcauchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("unknown_clap_name"), ScavTrap(), FragTrap()
{
	this->_name = ClapTrap::_name;
	std::cout << "DiamondTrap: Default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name)
{
	this->_name = name;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 30;
	std::cout << "DiamondTrap: Constructor with name called" << std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap const &src)
{
	std::cout << "DiamondTrap: Copy constructor called" << std::endl;
	*this = src;
}

DiamondTrap &DiamondTrap::operator=(DiamondTrap const &rhs)
{
	ClapTrap::operator=(rhs);
	return *this;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap: Default destructor called" << std::endl;
}

void	DiamondTrap::whoAmI()
{
	std::cout << "My name is " << this->_name << " and associated Clap Trap name is ";
	std::cout << ClapTrap::_name << std::endl;
}

void	DiamondTrap::attack(std::string str)
{
	ScavTrap::attack(str);
}
