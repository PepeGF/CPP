# include "Cat.hpp"

Cat::Cat()
{
	this->type = "Cat";
	this->_brain = new Brain();

	std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(std::string const type) : AAnimal(type)
{
	this->type = type;
	this->_brain = new Brain();

	std::cout << "Cat parametric constructor called" << std::endl;
}

Cat::Cat(const Cat& copy) : AAnimal()
{
	if (this != &copy)
	{
		this->type = copy.type;
		this->_brain = new Brain(*(copy._brain));
	}
	
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat::~Cat()
{
	delete _brain;
	std::cout << "Cat destructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& rhs)
{
	this->type = rhs.type;
	this->_brain = rhs._brain;

	std::cout << "Cat assignation operator called" << std::endl;
	return *this;
}

void Cat::makeSound(void) const
{
	std::cout << "I'm a Cat so I say: MIAU! MIAU!" << std::endl;
}

Brain* Cat::getBrain(void) const
{
	return this->_brain;
}
