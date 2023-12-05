#pragma once
#include <iostream>
#include "ICharacter.hpp"
#include "AMateria.hpp"


class Character
{
	private:
		std::string _name;
		AMateria* _materia[4];
	public:
		Character();
		Character(std::string name);
		Character(Character & const copy);
		virtual ~Character();

		Character& operator=(Character const & copy);
		
		std::string const & getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
};