#pragma once
#include <iostream>

class ClapTrap
{
private:

	std::string	_name;
	int			_hitpoints; //health
	int			_energy_points; //stamina
	int			_attack_damage;

public:
	ClapTrap();
	ClapTrap(std::string name);
	ClapTrap(ClapTrap &other);
	~ClapTrap();

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
