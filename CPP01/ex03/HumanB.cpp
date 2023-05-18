#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name)
{}

HumanB::HumanB()
{}

HumanB::~HumanB()
{}

void	HumanB::setWeapon(Weapon &w)
{
	std::cout << &w << std::endl;
	std::cout << &this->_weapon << std::endl;
	this->_weapon = &w;
	std::cout << &this->_weapon << std::endl;
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
