/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcauchet <jcauchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 14:56:00 by jcauchet          #+#    #+#             */
/*   Updated: 2022/09/30 17:05:02 by jcauchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie *zombieHorde(int N, std::string name)
{
	if (N < 1)
	{
		std::cout << "Number of zombies cannot be 0 or less than 0." << std::endl;
		return NULL;
	}
	Zombie *horde = new Zombie[N];
	for (int i = 0; i < N; i++)
		horde[i].set_name(name);
	return horde;
}
