# include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{}

Cure::Cure(std::string type) : AMateria("cure")
{
	this->_type = type;
}

Cure::Cure(const Cure& copy) : AMateria()
{
	if(this != &copy)
		this->_type = copy._type;
}

Cure::~Cure()
{}

Cure& Cure::operator=(const Cure& copy)
{
	this->_type = copy.getType();
	return (*this);
}

AMateria* Cure::clone() const
{
	AMateria* cure = new Cure(*this);
	return cure;
}

void Cure::use(ICharacter & target)
{
	std::cout << "* heals " << target.getName() << " wounds *" << std::endl;
}