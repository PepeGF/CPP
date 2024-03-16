# include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{}

Ice::Ice(std::string type) : AMateria("ice")
{
	this->_type = type;}

Ice::Ice(const Ice& copy) : AMateria(copy)
{
	if(this != &copy)
		this->_type = copy._type;
}

Ice::~Ice()
{}

Ice& Ice::operator=(const Ice& rhs)
{
	this->_type = rhs.getType();
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