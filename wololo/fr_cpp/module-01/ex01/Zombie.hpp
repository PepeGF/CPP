/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcauchet <jcauchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 10:14:18 by jcauchet          #+#    #+#             */
/*   Updated: 2022/09/30 16:35:49 by jcauchet         ###   ########.fr       */
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
	void	set_name(std::string name);
private:
	std::string name;
};

Zombie *zombieHorde(int N, std::string name);
