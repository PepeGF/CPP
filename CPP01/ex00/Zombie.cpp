#include "Zombie.hpp"

Zombie::Zombie( std::string name) : _name(name)
{
	Zombie::announce();
}

Zombie::~Zombie()
{
	std::cout << this->_name << ": zombie definitely dead" << std::endl;
}

void	Zombie::announce (void)
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
