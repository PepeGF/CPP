/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josgarci <josgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 18:19:31 by josgarci          #+#    #+#             */
/*   Updated: 2023/11/25 17:52:06 by josgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap()
{
	this->_name = "He who must not be named";
	this->_attack_damage = 20;
	this->_energy_points = 50;
	this->_hit_points = 100;

	std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	this->_attack_damage = 20;
	this->_energy_points = 50;
	this->_hit_points = 100;

	std::cout << "ScavTrap parameterized constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
	*this = other;

	std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &rhs)
{
	ClapTrap::operator=(rhs);
	std::cout << "ScavTrap assignation operator called" << std::endl;
	return (*this);
}

void ScavTrap::attack(const std::string &target)
{
	if (this->_hit_points <= 0)
	{
		std::cout << this->getName() << " unable to attack, it's dead!!!" << std::endl;
		return;
	}
	if (this->_energy_points <= 0)
	{
		std::cout << this->getName() << " unable to attack, no energy points available" << std::endl;
		return;
	}
	std::cout << this->getName() << " attacks " 
		<< target << ", causing " << this->_attack_damage 
		<< " points of damage!" << std::endl;
	this->_energy_points -= 1;
}

void ScavTrap::guardGate(void)
{
	if (this->_hit_points <= 0)
	{
		std::cout << this->getName() << " unable to guard gate, it's dead!!!" << std::endl;
		return;
	}
	std::cout << this->getName() << " is now in Gate keeper mode" << std::endl;
}