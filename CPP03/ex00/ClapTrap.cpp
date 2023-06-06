#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	this->_name = "Unnamed";
	this->_attack_damage = 0;
	this->_energy_points = 10;
	this->_hitpoints = 10;

	std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name)
{
	this->_attack_damage = 0;
	this->_energy_points = 10;
	this->_hitpoints = 10;

	std::cout << "Parameterized constructor called" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap &other)
{
	this->_name = other._name;
	this->_attack_damage = other._attack_damage;
	this->_energy_points = other._energy_points;
	this->_hitpoints = other._hitpoints;

	std::cout << "Copy constructor called" << std::endl;
}

ClapTrap::~ClapTrap()
{
	delete(this);

	std::cout << "Destructor called" << std::endl;
}

ClapTrap &ClapTrap::operator=(ClapTrap const &rhs)
{
	if (this != &rhs)
	{
		this->_name = rhs._name;
		this->_attack_damage = rhs._attack_damage;
		this->_energy_points = rhs._energy_points;
		this->_hitpoints = rhs._hitpoints;
	}

	std::cout << "Assignation operator called" << std::endl;
	return (*this);
}

void	ClapTrap::attack(std::string const &target)
{
	std::cout << "ClapTrap " << this->getName() << " attacks " 
			<< target << " causing " << this->getDamage()
			<< " points of damage" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	this->_energy_points -= amount;
	std::cout << "Uhg! That hurts!" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	this->_energy_points += amount;
}

std::string ClapTrap::getName()
{
	return(this->_name);
}

int	ClapTrap::getDamage()
{
	return(this->_hitpoints);
}

