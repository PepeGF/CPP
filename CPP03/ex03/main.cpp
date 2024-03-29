/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josgarci <josgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 18:19:28 by josgarci          #+#    #+#             */
/*   Updated: 2023/11/25 18:17:10 by josgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main()
{
	DiamondTrap voldemort("Voldemort");
	DiamondTrap onesiforo("Onesiforo");
	DiamondTrap *lupinicio = new DiamondTrap("Lupinicio");
	DiamondTrap *filogonio = new DiamondTrap(*lupinicio);

	std::cout << std::endl;

	std::cout << "Name: " << voldemort.getName() << "\n"
		<< "Energy: " << voldemort.getEnergyPoints() << "\n"
		<< "Hitpoints: " << voldemort.getHitPoints() << "\n"
		<< "Attack: " << voldemort.getAttackDamage() << std::endl; 
	std::cout << std::endl;

	for (int i = 1; i <= 5; i++)
	{
		// aquí hay un espacio entre el nombre y el tipo
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

	onesiforo.highFivesGuys();
	lupinicio->highFivesGuys();
	voldemort.highFivesGuys();
	onesiforo.guardGate();
	std::cout << std::endl;

	onesiforo.whoAmI();
	
	std::cout << std::endl;

	delete(lupinicio);
	delete(filogonio); 
	
	
	// system("leaks a.out");
	return (0);
}