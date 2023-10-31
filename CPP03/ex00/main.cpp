/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josgarci <josgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 18:17:07 by josgarci          #+#    #+#             */
/*   Updated: 2023/10/31 18:26:37 by josgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
	ClapTrap voldemort;
	std::cout << "·.·.·.·.·.·.·.·" << std::endl;
	ClapTrap onesiforo("Onesiforo");
	std::cout << "·.·.·.·.·.·.·.·" << std::endl;
	ClapTrap *lupinicio = new ClapTrap("Lupinicio");
	std::cout << "·.·.·.·.·.·.·.·" << std::endl;
	ClapTrap *filogonio = new ClapTrap(*lupinicio);
	std::cout << "·.·.·.·.·.·.·.·" << std::endl;

	std::cout << std::endl << "\t----- First part -----\n" << std::endl;

	for (int i = 0; i <= 10; i++)
	{
		onesiforo.attack("Lupinicio");
		lupinicio->takeDamage(onesiforo.getAttackDamage());
		if (i >= 3)
			onesiforo.setAttackDamage(i + 1);
	}

	std::cout << "\t----- Second part -----\n" << std::endl;

	std::cout << voldemort.getName() << ": ";
	voldemort.beRepaired(1000000);
	std::cout 	
		<< voldemort.getName() << " has " 
		<< voldemort.getEnergyPoints() 
		<< " energy points and " << voldemort.getHitPoints() 
		<< " hitpoints" << std::endl;
	lupinicio->beRepaired(100);
	onesiforo.beRepaired(100);

	std::cout << std::endl << "\t----- Last part -----\n" << std::endl;
	filogonio->attack("Onesiforo");

	std::cout << std::endl;

	delete(lupinicio);
	delete(filogonio);

	// system("leaks a.out");
	return (0);
}
