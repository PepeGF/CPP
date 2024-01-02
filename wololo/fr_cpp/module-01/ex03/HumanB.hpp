/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcauchet <jcauchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 10:47:57 by jcauchet          #+#    #+#             */
/*   Updated: 2022/10/04 14:20:18 by jcauchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Weapon.hpp"

class HumanB
{
public:
	HumanB(std::string name);
	void	attack() const;
	void	setWeapon(Weapon &w);
private:
	Weapon		*weapon;
	std::string	name;
};
