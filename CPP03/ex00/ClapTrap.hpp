#include <iostream>

class ClapTrap
{
private:

	std::string	_name;
	int			_hitpoints;
	int			_energy_points;
	int			_attack_damage;

public:
	ClapTrap();
	ClapTrap(std::string name);
	ClapTrap(ClapTrap &other);
	~ClapTrap();

	ClapTrap &operator=(ClapTrap const &rhs);

	void	attack(std::string const &target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);

	std::string	getName();
	int	getDamage();
};