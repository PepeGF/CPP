#include "phonebook.hpp"
#include <iomanip>

// Phonebook::Phonebook(/* args */)
// {
// 	return;
// }

// Phonebook::~Phonebook()
// {
// 	return;
// }


void Phonebook::print_table_header()
{
	// index, first name, last name, nickname
	for (int i = 1; i <= 45; i++)
		std::cout << "*";
	std::cout << std::endl;
	std::cout << "*   Index  |First Name| Last Name| Nickname *" << std::endl;
	for (int i = 1; i <= 45; i++)
		std::cout << "*";
	std::cout << std::endl;
	return ;
}

void Phonebook::print_table_tail()
{
	for (int i = 1; i <= 45; i++)
		std::cout << "*";
	std::cout << std::endl;
}

void Phonebook::print_table_body(int recorded)
{
	for (int i = 0; i <= recorded - 1; i++)
	{
		std::cout << "*";
		if (this->contacts[i].get_first_name().length() > 10)
			std::cout << this->contacts[i].get_first_name().substr(0, 9) << ".";
		else
			std::cout << std::right << std::setw(10) << this->contacts[i].get_first_name();
		std::cout << "|";
		if (this->contacts[i].get_last_name().length() > 10)
			std::cout << this->contacts[i].get_last_name().substr(0, 9) << ".";
		else
			std::cout << std::right << std::setw(10) << this->contacts[i].get_last_name();
		std::cout << "|";
		if (this->contacts[i].get_nickname().length() > 10)
			std::cout << this->contacts[i].get_nickname().substr(0, 9) << ".";
		else
			std::cout << std::right << std::setw(10) << this->contacts[i].get_nickname();
		std::cout << "|";
		if (this->contacts[i].get_phone().length() > 10)
			std::cout << this->contacts[i].get_phone().substr(0, 9) << ".";
		else
			std::cout << std::right << std::setw(10) << this->contacts[i].get_phone();
		std::cout << "*" << std::endl;
	}
}