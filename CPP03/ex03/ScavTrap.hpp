/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josgarci <josgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 18:19:36 by josgarci          #+#    #+#             */
/*   Updated: 2023/10/24 20:30:37 by josgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
	protected:
		static const int _energy = 50;
		
	public:
		ScavTrap(void);
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap &other);
		virtual ~ScavTrap(void);

		ScavTrap &operator=(const ScavTrap &rhs);

		void	attack(const std::string &target);
		void	guardGate(void);

};