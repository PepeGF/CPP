/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josgarci <josgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 18:18:56 by josgarci          #+#    #+#             */
/*   Updated: 2023/11/25 17:13:25 by josgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	this->_name = "He who must not be named";
	this->_attack_damage = 0;
	this->_energy_points = 10;
	this->_hit_points = 10;

	std::cout << "ClapTrap Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
{
	this->_name = name;
	this->_attack_damage = 0;
	this->_energy_points = 10;
	this->_hit_points = 10;

	std::cout << "ClapTrap Parameterized constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
	*this = other;

	std::cout << "ClapTrap Copy constructor called" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap Destructor called" << std::endl;
}

ClapTrap &ClapTrap::operator=(ClapTrap const &rhs)
{
	if (this != &rhs)
	{
		this->_name = rhs.getName();
		this->_attack_damage = rhs.getAttackDamage();
		this->_energy_points = rhs.getEnergyPoints();
		this->_hit_points = rhs.getHitPoints();
	}
	std::cout << "Assignation operator called" << std::endl;
	return (*this);
}

void	ClapTrap::attack(const std::string &target)
{
	if (this->_hit_points <= 0)
	{
		std::cout << this->_name << " unable to attack, it's dead!!!" << std::endl;
		return;
	}
	if (this->_energy_points <= 0)
	{
		std::cout << this->_name << " unable to attack, no energy points available" << std::endl;
		return;
	}
	std::cout << "ClapTrap " << this->getName() << " attacks " 
			<< target << " causing " << this->getAttackDamage()
			<< " points of damage" << std::endl;
	this->_energy_points--;
	return;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hit_points <= 0)
	{
		std::cout << this->_name << " no damage received, I'm dead!!!" << std::endl;
		return;
	}
	this->_hit_points -= amount;
	if (this->_hit_points < 0)
		this->_hit_points = 0;
	std::cout << "Uhg! That hurts!" << std::endl;
	std::cout << "Remaining energy points: " << this->_hit_points << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_hit_points <= 0)
	{
		std::cout << this->_name << " unable to heal, I'm dead!!" << std::endl;
		return;
	}
	if (this->_energy_points <= 0)
	{
		std::cout << this->_name << " unable to heal, no energy points available" << std::endl;
		return;
	}
	this->_hit_points += amount;
	this->_energy_points--;
	std::cout << "That's nice!" << std::endl;
}

std::string ClapTrap::getName(void) const
{
	return(this->_name);
}

int	ClapTrap::getAttackDamage(void) const
{
	return(this->_attack_damage);
}

void ClapTrap::setAttackDamage(unsigned int amount)
{
	this->_attack_damage = amount;
}

int	ClapTrap::getEnergyPoints(void) const
{
	return(this->_energy_points);
}

int	ClapTrap::getHitPoints(void) const
{
	return(this->_hit_points);
}
