# include "WrongCat.hpp"

WrongCat::WrongCat()
{
    this->type = "WrongCat";

    std::cout << "WrongCat default constructor called" << std::endl;
}

WrongCat::WrongCat(std::string const type) : WrongAnimal(type)
{
    this->type = type;

    std::cout << "WrongCat parametric constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& copy) : WrongAnimal(copy)
{
    if (this != &copy)
        *this = copy;
    
    std::cout << "WrongCat copy constructor called" << std::endl;
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat destructor called" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& rhs)
{
    this->type = rhs.type;

    std::cout << "WrongCat assignation operator called" << std::endl;
    return *this;
}

void WrongCat::makeSound() const
{
    std::cout << "I'm a WrongCat so I say: Nobita, Don't!" << std::endl;
}
