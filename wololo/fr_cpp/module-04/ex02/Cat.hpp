/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcauchet <jcauchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 10:08:38 by jcauchet          #+#    #+#             */
/*   Updated: 2022/10/11 10:11:42 by jcauchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Cat: public Animal
{
public:
	Cat();
	Cat(Cat const &src);
	Cat &operator=(Cat const &rhs);
	virtual ~Cat();

	std::string	getType() const;
	void	makeSound() const;
private:
	Brain *_brain;
};
