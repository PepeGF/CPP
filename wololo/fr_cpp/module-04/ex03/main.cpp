/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcauchet <jcauchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 09:44:16 by jcauchet          #+#    #+#             */
/*   Updated: 2022/10/12 14:23:05 by jcauchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"
#include "IMateriaSource.hpp"

/* int main()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	delete bob;
	delete me;
	delete src;
	return 0;
} */

int main()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(NULL);
	
	Character Yoshi("Yoshi");

	ICharacter *Tac = new Character("Tac");
	
	// Materia Ice cannot be created because nothing has been learnt before
	std::cout << "My name is " << Yoshi.getName() << std::endl;
	Yoshi.equip(src->createMateria("ice"));
	
	src->learnMateria(new Ice());
	Yoshi.equip(src->createMateria("ice"));
	
	Yoshi.use(0, *Tac);
	
	// There's nothing at index 1. Therefore the following line will not do anything
	Yoshi.unequip(1);
	
	Yoshi.unequip(0);
	// Materia Ice at index 0 has been unequiped and is now unavailable
	Yoshi.use(0, *Tac);
	delete src;
	delete Tac;
	return 0;
}
