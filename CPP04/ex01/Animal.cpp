# include "Animal.hpp"

Animal::Animal()
{
	std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(std::string type)
{
	this->type = type;
	std::cout << "Animal type constructor called" << std::endl;
}

Animal::Animal(const Animal& copy)
{
	if (this != &copy)
		*this = copy;
	std::cout << "Animal copy constructor called" << std::endl;
}

Animal::~Animal()
{
	std::cout << "Animal destructor called" << std::endl;
}

Animal& Animal::operator=(const Animal& obj)
{
	this->type = obj.type;
	return (*this);
}

std::string Animal::getType() const
{
	return (this->type);
}

void Animal::makeSound() const
{
	std::cout << "Hakuna Matata!!!" << std::endl;
}