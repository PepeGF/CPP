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

	std::cout << "Tipo tmp: " << tmp->getType() << std::endl;
	me->equip(tmp);

	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	std::cout << "---------------------------------------" << std::endl;

	me->unequip(2);
	me->unequip(1);

	delete tmp;
	delete bob;
	delete me;
	delete src;

	return 0;
}
	/* 
	std::cout << std::endl;
	IMateriaSource* src2 = new MateriaSource();
	src2->learnMateria(new Ice());
	src2->learnMateria(new Cure());

	Character* pepe = new Character("pepe");
	Character* juan = new Character("juan");
	// Character* maria = new Character("maria");

	std::cout << std::endl;
	AMateria* tmp2;
	tmp2 = src2->createMateria("ice");
	pepe->equip(tmp2);
	tmp2 = src2->createMateria("cure");
	pepe->equip(tmp2);
	juan = pepe;

	std::cout << std::endl;
	std::cout << juan->getName() << std::endl;
	juan->use(1, *pepe);
	pepe->unequip(1);
	juan->use(0, *pepe);
	pepe->use(0, *juan);
	pepe->equip(src2->createMateria("ice"));
	std::cout << std::endl;

	src2->createMateria("aaaa");
	pepe->use(3, *juan);
	pepe->use(-1, *juan);

	delete src2;
	delete pepe;
	// delete juan; 
	*/

