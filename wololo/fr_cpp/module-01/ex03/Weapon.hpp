/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcauchet <jcauchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 10:25:29 by jcauchet          #+#    #+#             */
/*   Updated: 2022/10/02 12:09:44 by jcauchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

class Weapon
{
public:
	Weapon();
	Weapon(std::string weapon);
	~Weapon();
	const std::string	&getType() const;
	void				setType(std::string type);
private:
	std::string type;
};
