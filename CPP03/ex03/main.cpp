/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josgarci <josgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 18:19:28 by josgarci          #+#    #+#             */
/*   Updated: 2023/10/31 17:38:06 by josgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main()
{
/* 	DiamondTrap voldemort("Voldemort");
	DiamondTrap onesiforo("Onesiforo");
	DiamondTrap *lupinicio = new DiamondTrap("Lupinicio");
	DiamondTrap *filogonio = new DiamondTrap(*lupinicio);

	std::cout << "Name: " << voldemort.getName() << "\n"
		<< "Energy: " << voldemort.getEnergyPoints() << "\n"
		<< "Hitpoints: " << voldemort.getHitpoints() << "\n"
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
		<< " energy points and " << voldemort.getHitpoints() 
		<< " hitpoints" << std::endl;
	lupinicio->beRepaired(100);
	onesiforo.beRepaired(100);
	std::cout << std::endl;

	filogonio->attack("Onesiforo");

	std::cout << std::endl;

	onesiforo.highFivesGuys();
	lupinicio->highFivesGuys();
	voldemort.highFivesGuys();

	std::cout << std::endl;


	delete(lupinicio);
	delete(filogonio); 
 */	
	ClapTrap pavon("Peivon");
	std::cout << "···············" << std::endl;
	ScavTrap jalvarad("Joso");
	std::cout << "···············" << std::endl;
	FragTrap nachito("Zipi");
	std::cout << "···············" << std::endl;
	DiamondTrap crisi("Crisi");
	std::cout << "···············" << std::endl;

	std::cout << "Diamond name: " << crisi.getName() << std::endl;
	std::cout << "Diamond hitpoints: " << crisi.getHitPoints() << std::endl;
	std::cout << "Diamond energy points: " << crisi.getEnergyPoints() << std::endl;
	std::cout << "Diamond attack damage: " << crisi.getAttackDamage() << std::endl;
	std::cout << "···············" << std::endl;

	crisi.whoAmI();
	std::cout << "···············" << std::endl;
	jalvarad.guardGate();
	nachito.highFivesGuys();
	pavon.attack("Zipi");
	nachito.takeDamage(0);
	nachito.attack("Peivon");
	pavon.takeDamage(30);
	std::cout << "···············" << std::endl;
	// system("leaks a.out");
	return (0);
}