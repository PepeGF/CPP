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

Character::Character(Character& const copy) //: _name(copy._name)
{
	if (this != &copy)
	{
		*this = copy;
		/* for (int i = 0; i < 4; i++)
		{
			this->_materia[i] = copy._materia[i];
		} 
		quitar el comentario si usar el operador de asignación funciona bien
		*/
	}
	std::cout << "Character copy constructor called" << std::endl;
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_materia[i])
			delete this->_materia[i];
	}
	std::cout << "Character destructor called" << std::endl;
}

Character& Character::operator=(Character const & copy)
{
	this->_name = copy._name;
	for (int i = 0; i < 4; i++)
	{
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
	if (idx >= 0 && idx < 4 && this->_materia[idx] != nullptr)
		this->_materia[idx] = nullptr;
	return ;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx >= 0 && idx < 4 && this->_materia[idx] != nullptr)
		this->_materia[idx]->use(target);
	return ;
}
