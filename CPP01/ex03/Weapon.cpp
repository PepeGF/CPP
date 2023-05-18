#include "Weapon.hpp"

Weapon::Weapon(std::string weapon)
{
	this->setType(weapon);
}

Weapon::Weapon()
{}

Weapon::~Weapon()
{}

const std::string	&Weapon::getType() const
{
	const std::string	&type_ref = this->_type;
	return (type_ref);
}

void Weapon::setType(std::string type)
{
	this->_type = type;
	return ;
}
