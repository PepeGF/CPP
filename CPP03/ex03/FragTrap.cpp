#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
    this->_name = "He who must not be named";
    this->_attack_damage = 30;
    this->_energy_points = 100;
    this->_hitpoints = 100;

    std::cout << "FragTrap Default constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    this->_name = name;
    this->_attack_damage = 30;
    this->_energy_points = 100;
    this->_hitpoints = 100;

    std::cout << "FragTrap Parameterized constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &other)
{
    this->_name = other._name;
    this->_attack_damage = other._attack_damage;
    this->_energy_points = other._energy_points;
    this->_hitpoints = other._hitpoints;

    std::cout << "FragTrap Copy constructor called" << std::endl;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap Destructor called" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &rhs)
{
    ClapTrap::operator=(rhs);
    std::cout << "FragTrap Assignation operator called" << std::endl;
    return (*this);
}

void FragTrap::highFivesGuys(void)
{
    if (this->_hitpoints <= 0)
    {
		std::cout << this->_name << " unable to hive five, it's dead!!!" << std::endl;
		return;
	}
    std::cout << "FragTrap " << this->_name << " says: High five guys!" << std::endl;
}