/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josgarci <josgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 18:19:00 by josgarci          #+#    #+#             */
/*   Updated: 2023/11/25 16:43:43 by josgarci         ###   ########.fr       */
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
		ClapTrap(void);
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap &other);
		virtual ~ClapTrap(void);

		ClapTrap &operator=(ClapTrap const &rhs);

		void	attack(const std::string &target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);

		std::string	getName(void) const;
		int			getAttackDamage(void) const;
		int			getEnergyPoints(void) const;
		int			getHitPoints(void) const;
		void		setAttackDamage(unsigned int amount);
};