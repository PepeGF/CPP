#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int main()
{
	{
		Weapon club = Weapon("crude spiked club");

		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	{
		Weapon club = Weapon("crude spiked club");

		HumanB jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}
	{
		Weapon katana = Weapon("katana");
		HumanB pepe("pepe");
		pepe.attack();
		pepe.setWeapon(katana);
		pepe.attack();
		katana.setType("katana afiladisima");
		pepe.attack();
		katana.setType("");
		//katana.setType();
		pepe.attack();
	}
	return 0;
}
