#include "Zombie.hpp"

Zombie::Zombie()
{
	Zombie::announce();
}

Zombie::~Zombie()
{
	std::cout << this->_name << " zombie definitely dead" << std::endl;
}

void	Zombie::announce (void)
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}


Zombie	*Zombie::newZombie( std::string name )
{
	(void)name;
	Zombie *newZombie = NULL;

	return (newZombie);
}

void	Zombie::randomChump( std::string name )
{
	(void) name;
	Zombie newZombie;
}
