/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcauchet <jcauchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 12:07:33 by jcauchet          #+#    #+#             */
/*   Updated: 2022/10/09 08:56:45 by jcauchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

class ClapTrap
{
public:
	ClapTrap();
	ClapTrap(std::string str);
	ClapTrap(ClapTrap const &src); // Copy constructor
	ClapTrap &operator=(ClapTrap const &rhs); // Affectation operator
	~ClapTrap();

	void	attack(const std::string &target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);

	std::string getName(int damage);
	std::string getName();
	int	getDamage();
	int	getHitPoints();
	int	getEnergyPoints();

	void	setDamage(int damage);
protected:
	std::string _name;
	int	_hitPoints;
	int _energyPoints;
	int	_attackDamage;
};
