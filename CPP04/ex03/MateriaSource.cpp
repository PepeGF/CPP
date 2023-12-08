#include "MateriaSource.hpp"
#include "AMateria.hpp"
#include "Cure.hpp"
#include "Ice.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		this->_materia[i] = NULL;
	}
	std::cout << "MateriaSource default constructor called" << std::endl;
}

MateriaSource::MateriaSource(MateriaSource const & copy) : IMateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		if (copy._materia[i])
		{
			if (copy._materia[i]->getType() == "cure")
				this->_materia[i] = new Cure();
			else if (copy._materia[i]->getType() == "ice")
				this->_materia[i] = new Ice();
		}
	}

	std::cout << "MateriaSource copy constructor called" << std::endl;
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_materia[i])
		{
			delete this->_materia[i];
			std::cout << "materia " << i << " deleted" << std::endl;
		}
	}
	std::cout << "MateriaSource destructor called" << std::endl;

}

MateriaSource& MateriaSource::operator=(const MateriaSource& rhs)
{
	if (this != &rhs)
	{
		for (int i = 0; i < 4; i++)
			this->_materia[i] = rhs._materia[i];
	}
	std::cout << "MateriaSource assignation operator called" << std::endl;
	return (*this);
}

void MateriaSource::learnMateria(AMateria* materia)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_materia[i] == NULL)
		{
			this->_materia[i] = materia;
			return ;
		}
	}
	return ;
}

AMateria* MateriaSource::createMateria(const std::string & type)
{
	AMateria* new_materia = NULL;

	for (int i = 0; i < 4; i++)
	{
		if (this->_materia[i] != NULL && this->_materia[i]->getType() == type)
		{
			new_materia = this->_materia[i]->clone();
			break;
		}
	}
	return (new_materia);
}
