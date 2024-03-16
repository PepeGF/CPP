# include "AMateria.hpp"

AMateria::AMateria() : _type("Generic materia")
{}

AMateria::AMateria(std::string const & type) : _type(type)
{}

AMateria::AMateria(AMateria const & copy)
{
	this->_type = copy._type;}

AMateria::~AMateria()
{}

AMateria& AMateria::operator=(AMateria const & rhs)
{
	this->_type = rhs._type;
	return *this;
}

std::string const &AMateria::getType() const
{
	return this->_type;
}

void AMateria::use(ICharacter &)
{}

