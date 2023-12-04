# include "Cure.hpp"

Cure::Cure()
{
	std::cout << "Cure default constructor called" << std::endl;
}

Cure::Cure(std::string type) : AMateria()
{
	this->_type = type;
	std::cout << "Cure default constructor called" << std::endl;
}

Cure::Cure(const Cure& copy) : AMateria()
{
	if(this != &copy)
		this->_type = copy._type;

	std::cout << "Cure default constructor called" << std::endl;
}

Cure::~Cure()
{
	std::cout << "Cure destructor called" << std::endl;
}

Cure& Cure::operator=(const Cure& copy)
{
	this->_type = copy._type;
	
	std::cout << "Cure assignation operator called" << std::endl;
}

Cure* Cure::clone() const
{
	Cure* cure = new Cure();
	return cure;
}

void Cure::use(ICharacter & target)
{
	return ;
}