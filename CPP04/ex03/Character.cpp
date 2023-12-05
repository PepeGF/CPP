#include "Character.hpp"

Character::Character() : _name("He who must not be named")
{
	for (int i = 0; i < 4; i++)
		this->_materia[i] = nullptr;
	std::cout << "Character default constructor called" << std::endl;
}

Character::Character(std::string name) : _name(name)
{
	for (int i = 0; i < 4; i++)
		this->_materia[i] = nullptr;
	std::cout << "Character parametrized constructor called" << std::endl;
}

Character::Character(Character& const copy) : _name(copy._name)
{
	if (this != &copy)
	{
		for (int i = 0; i < 4; i++)
		{
			if (copy._materia[i] != nullptr)
				*(this->_materia[i]) = *(copy._materia[i]);
		}
	}
	std::cout << "Character copy constructor called" << std::endl;
}

Character::~Character()
{
	std::cout << "Character destructor called" << std::endl;
}

Character& Character::operator=(Character const & copy)
{
	this->_name = copy._name;
	for (int i = 0; i < 4; i++)
	{
		if (copy._materia[i] != nullptr)
			this->_materia[i] = copy._materia[i];
	}
	return *this;
}

std::string const & Character::getName() const
{
	return (this->_name);
}

void Character::equip(AMateria* m)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_materia[i] == nullptr)
			this->_materia[i] = m;
	}
}

void Character::unequip(int idx)
{
	
	return ;
}
void use(int idx, ICharacter& target);