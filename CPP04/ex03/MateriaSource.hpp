#pragma once
# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
private:
	AMateria *_materia[4];
public:
	MateriaSource();
	MateriaSource(const MateriaSource& copy);
	~MateriaSource();

	MateriaSource& operator=(MateriaSource const & rhs);

	void learnMateria(AMateria*);
	AMateria* createMateria(const std::string & type);
};
