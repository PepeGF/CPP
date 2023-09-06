/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josgarci <josgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 18:17:02 by josgarci          #+#    #+#             */
/*   Updated: 2023/09/06 18:17:03 by josgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

class ClapTrap
{
private:

	std::string	_name;
	int			_hitpoints; //health
	int			_energy_points; //stamina
	int			_attack_damage;

public:
	ClapTrap();
	ClapTrap(std::string name);
	ClapTrap(ClapTrap &other);
	~ClapTrap();

	ClapTrap &operator=(ClapTrap const &rhs);

	void	attack(const std::string &target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);

	std::string	getName();
	int			getAttackDamage();
	void		setAttackDamage(unsigned int amount);
	int			getEnergyPoints();
	int			getHitpoints();
};
