#pragma once

#include <iostream>
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap
{
	private:
		std::string _name;

	public:
		DiamondTrap();
		DiamondTrap(std::string name);
		DiamondTrap(const DiamondTrap &other);
		~DiamondTrap();

		DiamondTrap &operator=(DiamondTrap &rhs);

		void whoAmI();
};