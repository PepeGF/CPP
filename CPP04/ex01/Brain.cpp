#include "Brain.hpp"


Brain::Brain()
{
    std::cout << "Brain default constructor called" << std::endl;
}

Brain::Brain(std::string* ideas)
{
    *(this->ideas) = *ideas;

    std::cout << "Brain parametrized constructor called" << std::endl;
}

Brain::Brain(const Brain& copy)
{
    if (this != &copy)
    {
        *this = copy;
    }
    std::cout << "Brain copy constructor called" << std::endl;
}

Brain& Brain::operator=(const Brain& rhs)
{
    for(int i = 0; i < 100; i++)
    {
        this->ideas[i] = rhs.ideas[i];
    }
    std::cout << "Brain assignation operator called" << std::endl;
    return *this;
}

Brain::~Brain()
{
    std::cout << "Brain desconstructor called" << std::endl;
    
}