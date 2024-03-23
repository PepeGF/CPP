#pragma once
#include <iostream>
#include "ICharacter.hpp"
#include "AMateria.hpp"

# define MAX_MATERIA 142


class Character : public ICharacter
{
	private:
		std::string _name;
		AMateria* _materia[4];
		static AMateria* _unequipedmateria[MAX_MATERIA];
		static int _charactercount;
		Character();
		
	public:
		Character(const std::string name);
		Character(const Character &  copy);
		virtual ~Character();

		Character& operator=(const Character & copy);
		
		std::string const & getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
};
