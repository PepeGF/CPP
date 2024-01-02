/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcauchet <jcauchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 12:19:21 by jcauchet          #+#    #+#             */
/*   Updated: 2022/10/09 17:15:19 by jcauchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
	FragTrap Tac("Tac");
	FragTrap Yoshi("Yoshi");
	
	std::cout << Yoshi.getName() << " has initially " << Yoshi.getHitPoints() << " hit points." << std::endl;
	
	Tac.attack(Yoshi.getName(Tac.getDamage()));
	std::cout << Yoshi.getName() << " has now " << Yoshi.getHitPoints() << " hit points." << std::endl;
	
	Yoshi.beRepaired(10);
	std::cout << Yoshi.getName() << " has now " << Yoshi.getHitPoints() << " hit points." << std::endl;
	
	std::cout << Tac.getName() << " has now " << Tac.getEnergyPoints() << " energy points because he attacked " << Yoshi.getName() << std::endl;
	std::cout << Yoshi.getName() << " has now " << Yoshi.getEnergyPoints() << " energy points because she has been repaired " << std::endl;

	Yoshi.highFivesGuys();
}
