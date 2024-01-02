/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcauchet <jcauchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 18:06:44 by jcauchet          #+#    #+#             */
/*   Updated: 2022/10/12 10:30:39 by jcauchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

#include "ICharacter.hpp"

class ICharacter;

class AMateria
{
public:
	AMateria();
	AMateria(AMateria const &src);
	AMateria &operator=(AMateria const &rhs);
	virtual ~AMateria();

	AMateria(std::string const &type);
	std::string const &getType() const;
	virtual AMateria  *clone() const = 0;
	virtual void use(ICharacter &target);
protected:
	std::string type;
};
