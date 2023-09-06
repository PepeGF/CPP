#pragma once

#include <iostream>
#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
	public:
		FragTrap();
		FragTrap(std::string name);
		FragTrap(const FragTrap &other);
		virtual ~FragTrap();

		FragTrap &operator=(const FragTrap &rhs);

		void	highFivesGuys(void);
};