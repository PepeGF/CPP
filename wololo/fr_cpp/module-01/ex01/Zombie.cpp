/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcauchet <jcauchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 10:16:32 by jcauchet          #+#    #+#             */
/*   Updated: 2022/09/30 16:38:44 by jcauchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie() {}

void	Zombie::set_name(std::string name)
{
	this->name = name;
}

Zombie::Zombie(std::string name) 
{
	this->name = name;
}

Zombie::~Zombie()
{
	std::cout << "👉 \033[1;37mDestruction of a Zombie called: \033[0m";
	std::cout << this->name << "." << std::endl;
}

void	Zombie::announce(void)
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..."	<< std::endl;
}
