/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcauchet <jcauchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 12:19:21 by jcauchet          #+#    #+#             */
/*   Updated: 2022/10/09 15:13:44 by jcauchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main()
{
	DiamondTrap Tac("Tac");
	std::cout << "Hit points: " << Tac.getHitPoints() << std::endl;
	std::cout << "Energy points: " << Tac.getEnergyPoints() << std::endl;
	std::cout << "Attack damage: " << Tac.getDamage() << std::endl;
	Tac.attack("Yoshi");
	std::cout << std::endl;
	
	Tac.guardGate();
	Tac.highFivesGuys();

	std::cout << std::endl;
	
	Tac.whoAmI();
}
