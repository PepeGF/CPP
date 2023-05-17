#include "Zombie.hpp"

void	randomChump( std::string name );
Zombie	*newZombie(std::string name);

int main()
{
	Zombie *lupinicio;

	randomChump("Onesiforo");
	lupinicio = newZombie("Lupinicio");
	delete(lupinicio);
	return (0);
}

void	randomChump( std::string name )
{
	Zombie ambrosio = Zombie(name);
	return ;
}

Zombie	*newZombie( std::string name )
{
	Zombie *newZombie = new Zombie(name);
	return (newZombie);
}
