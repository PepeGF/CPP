#include "FragTrap.hpp"

int main()
{
	FragTrap voldemort;
	FragTrap onesiforo("Onesiforo");
	FragTrap *lupinicio = new FragTrap("Lupinicio");
	FragTrap *filogonio = new FragTrap(*lupinicio);

	std::cout << std::endl;

	for (int i = 1; i <= 5; i++)
	{
		onesiforo.attack("lupinicio");
		lupinicio->takeDamage(onesiforo.getAttackDamage());
	}

	std::cout << std::endl;

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

	filogonio->attack("Onesiforo");

	std::cout << std::endl;

	onesiforo.highFivesGuys();
	lupinicio->highFivesGuys();
	voldemort.highFivesGuys();

	std::cout << std::endl;


	delete(lupinicio);
	delete(filogonio);

	system("leaks a.out");
	return (0);
}