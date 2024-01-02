/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcauchet <jcauchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 09:57:44 by jcauchet          #+#    #+#             */
/*   Updated: 2022/10/10 10:22:30 by jcauchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"

class Dog: public Animal
{
public:
	Dog();
	Dog(Dog const &src);
	Dog &operator=(Dog const &rhs);
	~Dog();

	std::string	getType() const;
	void	makeSound() const;
};
