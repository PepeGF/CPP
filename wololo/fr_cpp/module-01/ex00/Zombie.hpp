/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcauchet <jcauchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 10:14:18 by jcauchet          #+#    #+#             */
/*   Updated: 2022/09/30 17:07:28 by jcauchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Zombie
{
public:
	Zombie();
	Zombie(std::string name);
	~Zombie();
	void 	announce(void);
private:
	std::string name;
};

Zombie	*newZombie(std::string name);
void	randomChump(std::string name);

