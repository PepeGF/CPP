# include "AMateria.hpp"

AMateria::AMateria()
{
	this->_type = "Generic materia";
	std::cout << "AMateria default constructor called" << std::endl;
}

AMateria::AMateria(std::string const & type) : _type(type)
{
	std::cout << "AMateria parametrized constructor called" << std::endl;
}

AMateria::AMateria(AMateria const & copy)
{
	if (this != &copy)
	{
		this->_type = copy._type;
	}
	std::cout << "AMateria copy constructor called" << std::endl;
}

AMateria::~AMateria()
{
	std::cout << "AMateria default destructor called" << std::endl;
}

AMateria& AMateria::operator=(AMateria const & rhs)
{
	this->_type = rhs._type;
	std::cout << "AMateria assignation operator called" << std::endl;
	return *this;
}


