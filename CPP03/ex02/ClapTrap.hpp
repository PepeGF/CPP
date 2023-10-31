/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josgarci <josgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 18:18:05 by josgarci          #+#    #+#             */
/*   Updated: 2023/10/31 17:48:22 by josgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

class ClapTrap
{
	protected:

		std::string	_name;
		int			_hit_points;
		int			_energy_points;
		int			_attack_damage;

	public:
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap &other);
		virtual ~ClapTrap();

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
