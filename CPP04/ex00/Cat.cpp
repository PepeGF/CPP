# include "Cat.hpp"

Cat::Cat()
{
    this->type = "Cat";

    std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(std::string const type) : Animal(type)
{
    this->type = type;

    std::cout << "Cat parametric constructor called" << std::endl;
}

Cat::Cat(const Cat& copy) : Animal(copy)
{
    if (this != &copy)
        *this = copy;
    
    std::cout << "Cat copy constructor called" << std::endl;
}

Cat::~Cat()
{
    std::cout << "Cat destructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& rhs)
{
    this->type = rhs.type;

    std::cout << "Cat assignation operator called" << std::endl;
    return *this;
}

void Cat::makeSound() const
{
    std::cout << "I'm a Cat so I say: MIAU! MIAU!" << std::endl;
}
