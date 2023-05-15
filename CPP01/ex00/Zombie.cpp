#include "Zombie.hpp"

Zombie::Zombie()
{
	Zombie::announce();
}

Zombie::~Zombie()
{
	delete();
	std::cout << this->_name << " zombie definitely dead" << std::endl;
}

void	Zombie::announce (void)
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}


Zombie	Zombie::*newZombie( name )
{
	(void)name;
	Zombie *newZombie;

	newZombie = new(Zombie);
	return (newZombie);
}

void	Zombie::randomChump( name )
{
	Zombie newZombie;
}
