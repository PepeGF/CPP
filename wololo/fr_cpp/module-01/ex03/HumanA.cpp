/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcauchet <jcauchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 10:33:22 by jcauchet          #+#    #+#             */
/*   Updated: 2022/10/02 15:19:49 by jcauchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &w) : weapon(w)
{
	this->name = name;
}

void	HumanA::attack() const
{
	std::cout << this->name << " attacks with their " << this->weapon.getType();
	std::cout << std::endl;
}

