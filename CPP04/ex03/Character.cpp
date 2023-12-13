#include "Character.hpp"

Floor* Character::floor = new Floor();

Character::Character() : _name("He who must not be named")
{
	for (int i = 0; i < 4; i++)
		this->_materia[i] = NULL;
	std::cout << "Character default constructor called" << std::endl;
}

Character::Character(std::string name) : _name(name)
{
	for (int i = 0; i < 4; i++)
		this->_materia[i] = NULL;
	std::cout << "Character parametrized constructor called" << std::endl;
}

Character::Character(const Character& copy) : _name(copy._name)
{
	for (int i = 0; i < 4; i++)
	{
		if(copy._materia[i] != NULL)
		{
			this->_materia[i] = copy._materia[i]->clone();
		}
	}
	std::cout << "Character copy constructor called" << std::endl;
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_materia[i])
		{
			delete this->_materia[i];
			this->_materia[i] = NULL;
		}
	}
	std::cout << "Character destructor called" << std::endl;
}

Character& Character::operator=(Character const & copy)
{
	if (this != &copy)
	{
		this->_name = copy._name;
		for (int i = 0; i < 4; i++)
		{
			this->_materia[i] = copy._materia[i];
		}
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
		if (this->_materia[i] == NULL)
		{
			this->_materia[i] = m;
			return;
		}
	}
}

void Character::unequip(int idx)
{
	if (idx >= 0 && idx < 4 && this->_materia[idx] != NULL)
	{
		floor->insert(this->_materia[idx]);
		this->_materia[idx] = NULL;
	}
	return ;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx >= 0 && idx < 4 && this->_materia[idx] != NULL)
		this->_materia[idx]->use(target);
	return ;
}

/* 
void Character::getinventary() const
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_materia[i] == NULL)
			std::cout << "Slot " << i << ": empty" << std::endl;
		else
			std::cout << "Slot " << i << ": " << this->_materia[i]->getType() << std::endl;
	}
}
 */