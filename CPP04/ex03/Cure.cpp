# include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
	std::cout << "Cure default constructor called" << std::endl;
}

Cure::Cure(std::string type) : AMateria("cure")
{
	this->_type = type;
	std::cout << "Cure parametrized constructor called" << std::endl;
}

Cure::Cure(const Cure& copy) : AMateria()
{
	if(this != &copy)
		this->_type = copy._type;

	std::cout << "Cure copy constructor called" << std::endl;
}

Cure::~Cure()
{
	std::cout << "Cure destructor called" << std::endl;
}

Cure& Cure::operator=(const Cure& copy)
{
	this->_type = copy.getType();

	std::cout << "Cure assignation operator called" << std::endl;

	return (*this);
}

Cure* Cure::clone() const
{
	Cure* cure = new Cure(*this);
	return cure;
}

void Cure::use(ICharacter & target)
{
	std::cout << "* heals " << target.getName() << " wounds *" << std::endl;
	//potencialmente mejorable
}