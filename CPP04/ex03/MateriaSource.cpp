#include "MateriaSource.hpp"
#include "AMateria.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		this->_materia[i] = NULL
	}
	std::cout << "MateriaSource default constructor called" << std::endl;
}

MateriaSource::MateriaSource(MateriaSource const & rhs) : IMateriaSource()
{
	if (this != &rhs)
	{
		for (int i = 0; i < 4; i++)
		{
			this->_materia[i] = rhs._materia[i]
		}
	}

	std::cout << "MateriaSource copy constructor called" << std::endl;
	return (*this);
}

MateriaSource::~MateriaSource()
{
	std::cout << "MateriaSource destructor called" << std::endl;

}

MateriaSource& MateriaSource::operator=(const MateriaSource& rhs)
{
	for (int i = 0; i < 4; i++)
	{
		this->_materia[i] = copy._materia[i]
	}
	std::cout << "MateriaSource assignation operator called" << std::endl;
	return (*this);
}

void MateriaSource::learnMateria(AMateria* materia)
{
	(void)materia;
	// implementar
	return ;
}

AMateria* createMateria(const std::string & type)
{
	AMateria* materia = new AMateria(type);
	return (materia);
}
