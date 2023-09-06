#pragma once

#include <iostream>
#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
	public:
		ScavTrap();
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap &other);
		virtual ~ScavTrap();

		ScavTrap &operator=(const ScavTrap &rhs);

		void	attack(const std::string &target);
		void	guardGate();

};