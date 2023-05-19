#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name)
{
	this->_weapon = NULL;
}

HumanB::HumanB()
{
	this->_weapon = NULL;
}

HumanB::~HumanB()
{}

void	HumanB::setWeapon(Weapon &w)
{
	this->_weapon = &w;
}

void	HumanB::attack() const
{
	if (!this->_weapon)
		std::cout 
			<< this->_name 
			<< " attacks with their " 
			<< "bare handssss" 
			<< std::endl;
	else
		std::cout 
			<< this->_name 
			<< " attacks with their " 
			<< this->_weapon->getType()
			<< std::endl;
}
