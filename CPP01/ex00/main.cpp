#include "Zombie.hpp"

int main()
{
	Zombie *lupinicio;

	randomChump("Onesiforo");
	lupinicio = newZombie("Lupinicio");
	delete(lupinicio);
	return (0);
}
