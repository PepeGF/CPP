#include "ClapTrap.hpp"

int main()
{
	ClapTrap voldemort;
	ClapTrap onesiforo("Onesiforo");
	ClapTrap *lupinicio = new ClapTrap("Lupinicio");
	ClapTrap *filogonio = new ClapTrap(*lupinicio);

	std::cout << std::endl;

	for (int i = 0; i <= 11; i++)
	{
		onesiforo.attack("lupinicio");
		lupinicio->takeDamage(onesiforo.getAttackDamage());
		if (i == 5)
			onesiforo.setAttackDamage(i+1);
	}

	filogonio->attack("Onesiforo");
	std::cout << voldemort.getName() << std::endl;
	std::cout << filogonio->getName() << std::endl;
	delete(lupinicio);
	delete(filogonio);

	system("leaks a.out");
	return (0);
}