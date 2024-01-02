/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcauchet <jcauchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 12:12:41 by jcauchet          #+#    #+#             */
/*   Updated: 2022/10/09 17:05:47 by jcauchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _hitPoints(100), _energyPoints(50), _attackDamage(20)
{
	this->_name = "Unknown";
	std::cout << "ClapTrap: Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string str) : _name(str), _hitPoints(100), _energyPoints(50), _attackDamage(20)
{
	std::cout << "ClapTrap: Constructor with name called" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &src)
{
	std::cout << "ClapTrap: Copy constructor called" << std::endl;
	*this = src;
}

ClapTrap &ClapTrap::operator=(ClapTrap const &rhs)
{
	if (this != &rhs)
	{
		this->_name = rhs._name;
		this->_hitPoints = rhs._hitPoints;
		this->_energyPoints = rhs._energyPoints;
		this->_attackDamage = rhs._attackDamage;
	}
	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap: Default destructor called" << std::endl;
}

// Accessors

std::string ClapTrap::getName(int damage)
{
	this->takeDamage(damage);
	return this->_name;
}

std::string ClapTrap::getName()
{
	return this->_name;
}

int ClapTrap::getDamage()
{
	return this->_attackDamage;
}

int ClapTrap::getHitPoints()
{
	return this->_hitPoints;
}

int ClapTrap::getEnergyPoints()
{
	return this->_energyPoints;
}

void	ClapTrap::setDamage(int damage)
{
	this->_attackDamage = damage;
}

void	ClapTrap::attack(const std::string &target)
{
	std::cout << "ClapTrap ";
	if (this->_energyPoints > 0 && this->_hitPoints > 0)
	{
		std::cout << this->_name << " attacks " << target << ", causing ";
		std::cout << this->_attackDamage << " points of damage!" << std::endl;
		this->_energyPoints--;
	}
	else
		std::cout << this->_name << " couldn't attack!" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_energyPoints > 0 && this->_hitPoints > 0)
	{
		std::cout << this->_name << " received " << amount << " points of damage." << std::endl;
		this->_hitPoints = ((unsigned int)this->_hitPoints < amount) ? 0 : this->_hitPoints - amount;
	}
	else
		std::cout << this->_name << " couldn't take damage!" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energyPoints > 0 && this->_hitPoints > 0)
	{
		std::cout << this->_name << " has been repaired and received " << amount << " hit points." << std::endl;
		this->_hitPoints += amount;
		this->_energyPoints--;
	}
	else
		std::cout << this->_name << " couldn't be repaired!" << std::endl;
}
