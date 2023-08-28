#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	this->_name = "He who must not be named";
	this->_attack_damage = 20;
	this->_energy_points = 50;
	this->_hitpoints = 100;

	std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name)
{
	this->_name = name;
	this->_attack_damage = 20;
	this->_energy_points = 50;
	this->_hitpoints = 100;

	std::cout << "ScavTrap parameterized constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other)
{
	*this = other;

	std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &rhs)
{
	ClapTrap::operator=(rhs);
	std::cout << "ScavTrap assignation operator called" << std::endl;
	return (*this);
}

void ScavTrap::attack(const std::string &target)
{
	if (this->_hitpoints <= 0)
	{
		std::cout << this->_name << " unable to attack, it's dead!!!" << std::endl;
		return;
	}
	if (this->_energy_points <= 0)
	{
		std::cout << this->_name << " unable to attack, no energy points available" << std::endl;
		return;
	}
	std::cout << "ScavTrap " << this->_name << " attacks " 
		<< target << ", causing " << this->_attack_damage 
		<< " points of damage!" << std::endl;
	this->_energy_points -= 1;
}

void ScavTrap::guardGate()
{
	if (this->_hitpoints <= 0)
	{
		std::cout << this->_name << " unable to guard gate, it's dead!!!" << std::endl;
		return;
	}
	std::cout << "ScavTrap " << this->_name << " is now in Gate keeper mode" << std::endl;
}
