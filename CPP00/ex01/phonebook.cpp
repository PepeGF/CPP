#include "phonebook.hpp"

Phonebook::Phonebook(/* args */)
{
	return;
}

Phonebook::~Phonebook()
{
	return;
}

void Phonebook::add_contact()
{
	std::cout << "Introduce nombre: " << std::endl;
    std::getline(std::cin, _contacts->_first_name);
    return;
}