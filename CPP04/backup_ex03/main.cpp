#include <iostream>
#include "AMateria.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "ICharacter.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "Character.hpp"

int main()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");

	AMateria* tmp;
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("ice");
	me->equip(tmp);

	ICharacter* bob = new Character("bob");
	std::cout << "---------------------------------------\n" << std::endl;
	me->use(0, *bob);
	me->use(1, *bob);
	std::cout << "\n---------------------------------------" << std::endl;

	me->unequip(2);
	me->unequip(1);
	me->unequip(0);

	bob->equip(tmp);
	bob->unequip(0);

	delete bob;
	delete me;
	delete src;

	return 0;
}
	

