#include "ClapTrap.hpp"

int main()
{
	ClapTrap voldemort;
	ClapTrap onesiforo("Onesiforo");
	ClapTrap *lupinicio = new ClapTrap("Lupinicio");
	ClapTrap *filogonio = new ClapTrap(*lupinicio);

	std::cout << std::endl << " ----- First part -----" << std::endl;

	for (int i = 0; i <= 10; i++)
	{
		onesiforo.attack("Lupinicio");
		lupinicio->takeDamage(onesiforo.getAttackDamage());
		if (i >= 3)
			onesiforo.setAttackDamage(i + 1);
	}

	std::cout << std::endl << "----- Second part -----" << std::endl;

	std::cout << voldemort.getName() << ": ";
	voldemort.beRepaired(1000000);
	std::cout 	
		<< voldemort.getName() << " has " 
		<< voldemort.getEnergyPoints() 
		<< " energy points and " << voldemort.getHitpoints() 
		<< " hitpoints" << std::endl;
	lupinicio->beRepaired(100);
	onesiforo.beRepaired(100);
	std::cout << std::endl;

	std::cout << std::endl << "----- Last part -----" << std::endl;
	filogonio->attack("Onesiforo");

	std::cout << std::endl;

	delete(lupinicio);
	delete(filogonio);

	// system("leaks a.out");
	return (0);
}
