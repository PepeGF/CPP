/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josgarci <josgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 18:17:27 by josgarci          #+#    #+#             */
/*   Updated: 2023/09/06 18:17:47 by josgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

class ClapTrap
{
	protected:

		std::string	_name;
		int			_hitpoints;
		int			_energy_points;
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

		std::string	getName();
		int			getAttackDamage();
		void		setAttackDamage(unsigned int amount);
		int			getEnergyPoints();
		int			getHitpoints();
};
