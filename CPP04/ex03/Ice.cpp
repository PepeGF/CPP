# include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
	std::cout << "Ice default constructor called" << std::endl;
}

Ice::Ice(std::string type) : AMateria("ice")
{
	this->_type = type;
	std::cout << "Ice parametrized constructor called" << std::endl;
}

Ice::Ice(const Ice& copy) : AMateria()
{
	if(this != &copy)
		this->_type = copy._type;

	std::cout << "Ice copy constructor called" << std::endl;
}

Ice::~Ice()
{
	std::cout << "Ice destructor called" << std::endl;
}

Ice& Ice::operator=(const Ice& rhs)
{
	this->_type = rhs.getType();
	
	std::cout << "Ice assignation operator called" << std::endl;
	
	return (*this);
}

Ice* Ice::clone() const
{
	Ice* ice = new Ice(*this);
	return ice;
}

void Ice::use(ICharacter & target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}