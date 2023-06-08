#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	this->_name = "He who must not be named";
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

void	ClapTrap::attack(const std::string &target)
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
	std::cout << "ClapTrap " << this->getName() << " attacks " 
			<< target << " causing " << this->getAttackDamage()
			<< " points of damage" << std::endl;
	this->_energy_points--;
	return;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hitpoints <= 0)
	{
		std::cout << this->_name << " no damage received, I'm dead!!!" << std::endl;
		return;
	}
	this->_hitpoints -= amount;
	if (this->_hitpoints < 0)
		this->_hitpoints = 0;
	std::cout << "Uhg! That hurts!" << std::endl;
	std::cout << "Remaining energy points: " << this->_energy_points << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_hitpoints <= 0)
	{
		std::cout << this->_name << " unable to heal, I'm dead!!" << std::endl;
		return;
	}
	if (this->_energy_points <= 0)
	{
		std::cout << this->_name << " unable to heal, no energy points available" << std::endl;
		return;
	}
	this->_hitpoints += amount;
	this->_energy_points--;
	std::cout << "That's nice!" << std::endl;
}

std::string ClapTrap::getName()
{
	return(this->_name);
}

int	ClapTrap::getAttackDamage()
{
	return(this->_attack_damage);
}

void ClapTrap::setAttackDamage(unsigned int amount)
{
	this->_attack_damage = amount;
}

int	ClapTrap::getEnergyPoints()
{
	return(this->_energy_points);
}

int	ClapTrap::getHitpoints()
{
	return(this->_hitpoints);
}
