# include "AAnimal.hpp"

AAnimal::AAnimal()
{
	std::cout << "Animal default constructor called" << std::endl;
}

AAnimal::AAnimal(std::string type)
{
	this->type = type;
	std::cout << "Animal type constructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal& copy)
{
	if (this != &copy)
		*this = copy;
	std::cout << "Animal copy constructor called" << std::endl;
}

AAnimal::~AAnimal()
{
	std::cout << "Animal destructor called" << std::endl;
}

AAnimal& AAnimal::operator=(const AAnimal& obj)
{
	this->type = obj.type;
	return (*this);
}

std::string AAnimal::getType() const
{
	return (this->type);
}
