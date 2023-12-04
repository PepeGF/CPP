#pragma once
# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
private:
    std::string _type;
public:
    MateriaSource();
    MateriaSource();
    MateriaSource();
    ~MateriaSource();

    MateriaSource& operator=(MateriaSource & const rhs);

    void learnMateria(AMateria*);
    AMateria* createMateria(std::string & const type);
};
