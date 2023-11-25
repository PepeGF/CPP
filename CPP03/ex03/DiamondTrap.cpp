/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josgarci <josgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 18:19:04 by josgarci          #+#    #+#             */
/*   Updated: 2023/11/25 17:31:41 by josgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
{
	//this->_name = "He who shall not be named"; //probar a jugar con esto
	this->ClapTrap::_name = this->_name.append("_clap_name");
	this->_hit_points = FragTrap::_hit;
	this->_energy_points = ScavTrap::_energy;
	this->_attack_damage = FragTrap::_damage;

	std::cout << "DiamondTrap default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name)
{
	// this->ClapTrap::_name = this->_name.append("_clap_name");
	std::cout << "DiamondTrap constructor called" << std::endl;
	this->_name = name;
	this->_hit_points = FragTrap::_hit;
	this->_energy_points = ScavTrap::_energy;
	this->_attack_damage = FragTrap::_damage;

}

DiamondTrap::DiamondTrap(const DiamondTrap &other) : ClapTrap(other), ScavTrap(other), FragTrap(other)
{
	*this = other;

	std::cout << "DiamondTrap copy constructor called" << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap destructor called" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &rhs)
{
	this->ClapTrap::_name = rhs.ClapTrap::_name;
	this->_name = rhs._name;
	this->_attack_damage = rhs._attack_damage;
	this->_hit_points = rhs._hit_points;
	this->_energy_points = rhs._energy_points;

	std::cout << "DiamondTrap assignation operator called" << std::endl;
	return (*this);
}

void DiamondTrap::whoAmI()
{
	std::cout << "My DiamondTrap name: " << this->_name << "\n"
		<< " and my Diamond clapTrap name: " << this->getName()
		<< std::endl;
}

void DiamondTrap::attack(const std::string &target)
{
	this->ScavTrap::attack(target);
}
