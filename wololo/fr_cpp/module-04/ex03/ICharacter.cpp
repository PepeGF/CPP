/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcauchet <jcauchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 10:03:52 by jcauchet          #+#    #+#             */
/*   Updated: 2022/10/12 11:27:45 by jcauchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ICharacter.hpp"

ICharacter::ICharacter() {}

ICharacter::ICharacter(ICharacter const &src)
{
	*this = src;
}

ICharacter	&ICharacter::operator=(ICharacter const &)
{
	return *this;
}

ICharacter::~ICharacter() {}
