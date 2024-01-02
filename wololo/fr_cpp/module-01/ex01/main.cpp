/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcauchet <jcauchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 10:12:51 by jcauchet          #+#    #+#             */
/*   Updated: 2022/10/03 10:31:30 by jcauchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(int ac, char **av)
{
	if (ac != 3)
	{
		std::cout << "Please use correct syntax:";
		std::cout << "./[executable] [zombie_name] [zombie_amount]" << std::endl;
		return (1);
	}
	std::string name = av[1];
	int	amount = atoi(av[2]);
	Zombie *horde = zombieHorde(amount, name);
	for (int i = 0; i < amount; i++)
		horde[i].announce();
	delete [] horde;
}
