#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name)
{}

HumanB::HumanB()
{}

HumanB::~HumanB()
{}

void	HumanB::setWeapon(Weapon &weapon)
{
	this->_weapon = &weapon;
}

void	HumanB::attack() const
{
	if (!this->_weapon)
		std::cout 
			<< this->_name 
			<< " attacks with their " 
			<< "bare hands" 
			<< std::endl;
	else
		std::cout 
			<< this->_name 
			<< " attacks with their " 
			<< this->_weapon->getType()
			<< std::endl;
}