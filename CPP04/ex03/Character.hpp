#pragma once
#include <iostream>
#include "ICharacter.hpp"
#include "AMateria.hpp"
#include "Floor.hpp"


class Character : public ICharacter
{
	private:
		std::string _name;
		AMateria* _materia[4];
		static Floor* floor;

	public:
		Character();
		Character(std::string name);
		Character(const Character &  copy);
		virtual ~Character();

		Character& operator=(const Character & copy);
		
		std::string const & getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);

		void getinventary() const;
};