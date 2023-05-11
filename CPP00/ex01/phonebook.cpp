#include "phonebook.hpp"

Phonebook::Phonebook(/* args */)
{
	return;
}

Phonebook::~Phonebook()
{
	return;
}

int Phonebook::add_contact(int index)
{
	std::cout << "Introduce nombre: " << std::endl;
	// std::cin >> contacts[0].first_name;
    std::getline(std::cin, contacts[index].first_name);
	// if (std::cin.eof())
	// {
	// 	std::cin.clear();
	// 	return ;
	// }
	while (contacts[index].first_name.empty())
	{
		std::cout << "El nombre no puede ser un campo vacío" << std::endl;
		std::cout << "Introduce nombre: " << std::endl;
		if (!std::getline(std::cin, contacts[0].first_name))
			break;
		
	}
	
	return;
}

void Phonebook::print_table_header()
{
	// index, first name, last name, nickname
	for (int i = 1; i <= 45; i++)
		std::cout << "*";
	std::cout << std::endl;

	return ;
}