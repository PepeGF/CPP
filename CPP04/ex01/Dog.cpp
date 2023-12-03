# include "Dog.hpp"

Dog::Dog()
{
    this->type = "Dog";
    this->_brain = new Brain();
    std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(std::string const type) : Animal(type)
{
    this->type = type;
	this->_brain = new Brain();

    std::cout << "Dog parametric constructor called" << std::endl;
}

Dog::Dog(const Dog& copy) : Animal(copy)
{
	if (this != &copy)
	{
		this->type = copy.type;
		this->_brain = new Brain(*(copy._brain));
	}
    std::cout << "Dog copy constructor called" << std::endl;
}

Dog::~Dog()
{
    delete _brain;
    std::cout << "Dog destructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& rhs)
{
    this->type = rhs.type;
	this->_brain = rhs._brain;

    std::cout << "Dog assignation operator called" << std::endl;
    return *this;
}

void Dog::makeSound() const
{
    std::cout << "I'm a dog so I say: GUAU! GUAU!" << std::endl;
}

Brain* Dog::getBrain(void) const
{
	return this->_brain;
}