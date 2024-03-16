#include "Character.hpp"

int Character::_charactercount = 0;
AMateria* Character::_unequipedmateria[MAX_MATERIA] = {NULL};

Character::Character() : _name("He who must not be named")
{
	Character::_charactercount++;
	for (int i = 0; i < 4; i++)
		this->_materia[i] = NULL;
	for (int j = 0; j < MAX_MATERIA; j++)
		this->_unequipedmateria[j] = NULL;
}

Character::Character(std::string name) : _name(name)
{
	_charactercount++;
	for (int i = 0; i < 4; i++)
		this->_materia[i] = NULL;
	for (int j = 0; j < MAX_MATERIA; j++)
		this->_unequipedmateria[j] = NULL;
}

Character::Character(const Character& copy) : _name(copy._name)
{
	Character::_charactercount++;
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
}

Character::~Character()
{
	Character::_charactercount--;
	for (int i = 0; i < 4; i++)
	{
		if (this->_materia[i])
		{
			delete this->_materia[i];
			this->_materia[i] = NULL;
		}
	}
	if (Character::_charactercount == 0)
	{
		for (int j = 0; j < MAX_MATERIA; j++)
		{
			if (Character::_unequipedmateria[j])
			{
				delete Character::_unequipedmateria[j];
				Character::_unequipedmateria[j] = NULL;
			}
		}
	}
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
			if (Character::_unequipedmateria[MAX_MATERIA - 1] != NULL)
			{
				std::cout << "Unable to unequip materia, no space available" << std::endl;
				return;
			}
			if (Character::_unequipedmateria[i] == NULL)
				{
					Character::_unequipedmateria[i] = this->_materia[idx];
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
