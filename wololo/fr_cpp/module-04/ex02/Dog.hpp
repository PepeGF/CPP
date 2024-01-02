/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcauchet <jcauchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 09:57:44 by jcauchet          #+#    #+#             */
/*   Updated: 2022/10/11 10:11:47 by jcauchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Dog: public Animal
{
public:
	Dog();
	Dog(Dog const &src);
	Dog &operator=(Dog const &rhs);
	virtual ~Dog();

	std::string	getType() const;
	void	makeSound() const;
private:
	Brain *_brain;
};
