#include "Character.hpp"

Character::Character() : _name("He who must not be named")
{
	for (int i = 0; i < 4; i++)
		this->_materia[i] = NULL;
	for (int j = 0; j < MAX_MATERIA; j++)
		this->_unequipedmateria[j] = NULL;
	std::cout << "Character default constructor called" << std::endl;
}

Character::Character(std::string name) : _name(name)
{
	for (int i = 0; i < 4; i++)
		this->_materia[i] = NULL;
	for (int j = 0; j < MAX_MATERIA; j++)
		this->_unequipedmateria[j] = NULL;
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
	for (int j = 0; j < MAX_MATERIA; j++)
	{
		if(copy._unequipedmateria[j] != NULL)
		{
			this->_unequipedmateria[j] = copy._unequipedmateria[j]->clone();
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
	for (int j = 0; j < MAX_MATERIA; j++)
	{
		if (this->_unequipedmateria[j])
		{
			delete this->_unequipedmateria[j];
			this->_unequipedmateria[j] = NULL;
		}
	}
	// delete[] this->_materia;
	// delete[] this->_unequipedmateria;
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
		for (int j = 0; j < MAX_MATERIA; j++)
		{
			this->_unequipedmateria[j] = copy._unequipedmateria[j];
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
		for (int i = 0; i < MAX_MATERIA; i++)
		{
			if (this->_unequipedmateria[MAX_MATERIA - 1] != NULL)
			{
				std::cout << "Unable to unequip materia, no space available" << std::endl;
				return;
			}
			if (this->_unequipedmateria[i] == NULL)
				{
					this->_unequipedmateria[i] = this->_materia[idx];
					break ;
				}
		}
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