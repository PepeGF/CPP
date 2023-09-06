#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
{
	this->_name = "He who shall not be named"; //probar a jugar con esto
	this->ClapTrap::_name = this->_name.append("_clap_name");
	this->_hitpoints = FragTrap::_hitpoints;
	this->_energy_points = ScavTrap::_energy_points;
	this->_attack_damage = FragTrap::_attack_damage;

	std::cout << "DiamondTrap default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name)
{
	this->ClapTrap::_name = this->_name.append("_clap_name");
	this->_name = name;
	this->_hitpoints = FragTrap::_hitpoints;
	this->_energy_points = ScavTrap::_energy_points;
	this->_attack_damage = FragTrap::_attack_damage;

	std::cout << "DiamondTrap constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other) : ClapTrap(other), ScavTrap(other), FragTrap(other)
{
	*this = other;

	std::cout << "DiamondTrap copy constructor called" << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap destructor called" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &rhs)
{
	this->ClapTrap::_name = rhs.ClapTrap::_name;
	this->_name = rhs._name;
	this->_attack_damage = rhs._attack_damage;
	this->_hitpoints = rhs._hitpoints;
	this->_energy_points = rhs._energy_points;

	std::cout << "DiamondTrap assignation operator called" << std::endl;
	return (*this);
}

void DiamondTrap::whoAmI()
{
	std::cout << "My DiamondTrap name: " << this->_name 
		<< " and my ClapTrap name: " << this->ClapTrap::_name 
		<< std::endl;
}

void DiamondTrap::attack(const std::string &target)
{
	this->ScavTrap::attack(target);
}
