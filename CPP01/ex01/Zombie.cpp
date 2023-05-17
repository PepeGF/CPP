#include "Zombie.hpp"

Zombie::Zombie( std::string name) : _name(name)
{
	Zombie::announce();
}

Zombie::Zombie() : _name("zombie")
{
	std::cout << "It's alive!" << std::endl;
}

Zombie::~Zombie()
{
	std::cout << this->_name << ": zombie definitely dead" << std::endl;
}

void	Zombie::announce (void) const
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::set_name (std::string name)
{
	this->_name = name;
	this->announce();
	return ;
}
