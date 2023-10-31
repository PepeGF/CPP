/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josgarci <josgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 18:17:29 by josgarci          #+#    #+#             */
/*   Updated: 2023/10/31 18:46:24 by josgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main()
{
	ScavTrap voldemort;
	ScavTrap onesiforo("Onesiforo");
	ScavTrap *lupinicio = new ScavTrap("Lupinicio");
	ScavTrap *filogonio = new ScavTrap(*lupinicio);

	std::cout << std::endl;

	for (int i = 1; i <= 7; i++)
	{
		onesiforo.attack("lupinicio");
		lupinicio->takeDamage(onesiforo.getAttackDamage());
	}

	std::cout << std::endl;

	std::cout << voldemort.getName() << ": ";
	voldemort.beRepaired(1000000);
	std::cout 	
		<< voldemort.getName() << " has " 
		<< voldemort.getEnergyPoints() 
		<< " energy points and " << voldemort.getHitPoints() 
		<< " hitpoints" << std::endl;
	lupinicio->beRepaired(100);
	onesiforo.beRepaired(100);
	std::cout << std::endl;

	filogonio->attack("Onesiforo");

	std::cout << std::endl;

	onesiforo.guardGate();
	lupinicio->guardGate();
	voldemort.guardGate();

	std::cout << std::endl;

	delete(lupinicio);
	delete(filogonio);

	// system("leaks a.out");
	return (0);
}