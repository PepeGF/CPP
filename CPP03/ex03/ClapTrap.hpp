#pragma once

#include <iostream>

class ClapTrap
{
	protected:

		std::string	_name;
		int			_hitpoints;
		int			_energy_points;
		int			_attack_damage;

	public:
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap &other);
		virtual ~ClapTrap();

		ClapTrap &operator=(ClapTrap const &rhs);

		void	attack(const std::string &target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);

		std::string	getName();
		int			getAttackDamage();
		void		setAttackDamage(unsigned int amount);
		int			getEnergyPoints();
		int			getHitpoints();
};