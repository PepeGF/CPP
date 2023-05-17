#include "Zombie.hpp"

int	main()
{
	Zombie	*horde;
	int		quantity[] = {10, 1, 0, -10};
	std::string round[] = {"fisrt", "second", "third", "fourth"};

	for (int i = 0; i < 4; i++)
	{
		horde = zombieHorde(quantity[i], round[i]);
		std::cout << round[i] << " horde address: " << horde << std::endl;
		delete[] horde;
		std::cout << std::endl;
	}
	return (0);
}