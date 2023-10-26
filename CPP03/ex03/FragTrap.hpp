/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josgarci <josgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 18:19:16 by josgarci          #+#    #+#             */
/*   Updated: 2023/10/26 21:29:59 by josgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
	protected:
		static const int _hit = 100;
		static const int _damage = 30;
	public:
		FragTrap(void);
		FragTrap(std::string name);
		FragTrap(const FragTrap &other);
		virtual ~FragTrap();

		FragTrap &operator=(const FragTrap &rhs);

		void	highFivesGuys(void);
};