#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "Brain default constructor called" << std::endl;
}

Brain::Brain(std::string* ideas)
{
    for (int i = 0; i < 100; i++)
        this->ideas[i] = ideas[i];


    std::cout << "Brain parametrized constructor called" << std::endl;
}

Brain::Brain(Brain const &copy)
{
    if (this != &copy)
    {
        for (int i = 0; i < 100; i++)
            this->ideas[i] = copy.ideas[i];
    }
    std::cout << "Brain copy constructor called" << std::endl;
}

Brain& Brain::operator=(Brain const &rhs)
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
    std::cout << "Brain destructor called" << std::endl;
}

void Brain::setIdeas(std::string idea)
{
    for (int i = 0; i < 100; i++)
        this->ideas[i] = idea;
}

std::string Brain::getIdea(const int i)
{
    if (i >= 0 && i < 100)
        return this->ideas[i];
    return "Idea out of range";
}