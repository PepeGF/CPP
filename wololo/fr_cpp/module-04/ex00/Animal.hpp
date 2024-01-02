/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcauchet <jcauchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 09:45:21 by jcauchet          #+#    #+#             */
/*   Updated: 2022/10/10 10:25:19 by jcauchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

class Animal
{
public:
	Animal();
	Animal(Animal const &src);
	Animal &operator=(Animal const &rhs);
	virtual ~Animal();
	
	std::string	getType() const;
	virtual void	makeSound() const;
protected:
	std::string type;
};
