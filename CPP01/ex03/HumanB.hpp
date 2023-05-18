#include "Weapon.hpp"
#include <iostream>

class HumanB
{
	private:

		Weapon 		*_weapon;
		std::string	_name;

	public:

		HumanB(std::string name);
		HumanB();
		~HumanB();

		void	attack() const;
		void	setWeapon(Weapon &weapon);

};