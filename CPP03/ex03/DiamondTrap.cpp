#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
{
	this->_name = "He who shall not be named"; //probar a jugar con esto
	this->ClapTrap::_name = this->_name + "_clap_name";
	this->_hitpoints = FragTrap::_hitpoints;
	this->_energy_points = ScavTrap::_energy_points;
	this->_attack_damage = FragTrap::_attack_damage;

	std::cout << "DiamondTrap default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name)
{
	this->_name = name;
	this->ClapTrap::_name = this->_name + "_clap_name";
	this->_hitpoints = FragTrap::_hitpoints;
	this->_energy_points = ScavTrap::_energy_points;
	this->_attack_damage = FragTrap::_attack_damage;

	std::cout << "DiamondTrap constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other)
{
	this->_name = other._name;
	this->ClapTrap::_name = other._name + "_clap_name";
	this->_attack_damage = other._attack_damage;
	this->_hitpoints = other._hitpoints;
	this->_energy_points = other._energy_points;

	std::cout << "DiamondTrap copy constructor called" << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap destructor called" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &rhs)
{
	this->_name = rhs._name;
	this->ClapTrap::_name = rhs._name + "_clap_name";
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
