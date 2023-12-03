# include "Dog.hpp"

Dog::Dog()
{
    this->type = "Dog";

    std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(std::string const type) : Animal(type)
{
    this->type = type;

    std::cout << "Dog parametric constructor called" << std::endl;
}

Dog::Dog(const Dog& copy) : Animal(copy)
{
    if (this != &copy)
        *this = copy;
    
    std::cout << "Dog copy constructor called" << std::endl;
}

Dog::~Dog()
{
    std::cout << "Dog destructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& rhs)
{
    this->type = rhs.type;

    std::cout << "Dog assignation operator called" << std::endl;
    return *this;
}

void Dog::makeSound() const
{
    std::cout << "I'm a Dog so I say: GUAU! GUAU!" << std::endl;
}
