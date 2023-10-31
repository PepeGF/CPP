/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josgarci <josgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 18:17:02 by josgarci          #+#    #+#             */
/*   Updated: 2023/10/31 18:52:18 by josgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

class ClapTrap
{
private:

	std::string	_name;
	int			_hit_points; //health
	int			_energy_points; //stamina
	int			_attack_damage;

public:
	ClapTrap();
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap &other);
	~ClapTrap();

	ClapTrap &operator=(ClapTrap const &rhs);

	void	attack(const std::string &target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);

	std::string	getName(void) const;
	int			getAttackDamage(void) const;
	void		setAttackDamage(unsigned int amount);
	int			getEnergyPoints(void) const;
	int			getHitPoints(void) const;
};
