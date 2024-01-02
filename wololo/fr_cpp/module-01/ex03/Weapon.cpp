/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcauchet <jcauchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 10:38:47 by jcauchet          #+#    #+#             */
/*   Updated: 2022/10/04 13:52:21 by jcauchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon() {}
Weapon::~Weapon() {}

Weapon::Weapon(std::string weapon)
{
	this->setType(weapon);
}

const std::string	&Weapon::getType() const
{
	const std::string &ref = this->type;
	return ref;
}

void	Weapon::setType(std::string type)
{
	this->type = type;
}
