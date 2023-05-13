#include "phonebook.hpp"
#include "contact.hpp"
#include <iomanip>

int main()
{
	Phonebook	cuaderno;
	std::string	line;
	int			index;
	int			recorded;

	index = 1;
	recorded = 0;
	while (true)
	{
		std::cout << "Insert your command, please: " << std::endl;
		std::getline(std::cin, line);
		if (line == "ADD")
		{
			if (index == 9)
			{
				index = 1;
			}
			cuaderno.contacts[index - 1].add_contact();
			// cuaderno.contacts[index - 1].print_cosas();
			index++;
			recorded++;
			if (recorded > 8)
				recorded = 8;
			if (std::cin.eof())
			{
				std::cin.clear();
			}
			continue;
			// añadir contacto
		}
		else if (line == "SEARCH")
		{
			std::cout << "Searching..." << std::endl;
			cuaderno.print_table_header();
			cuaderno.print_table_body(recorded);
			/* for (int i = 0; i <= recorded - 1; i++)
			{
				std::cout << "*";
				if (cuaderno.contacts[i].get_first_name().length() > 10)
					std::cout << cuaderno.contacts[i].get_first_name().substr(0, 9) << ".";
				else
					std::cout << std::right << std::setw(10) << cuaderno.contacts[i].get_first_name();
				std::cout << "|";
				if (cuaderno.contacts[i].get_last_name().length() > 10)
					std::cout << cuaderno.contacts[i].get_last_name().substr(0, 9) << ".";
				else
					std::cout << std::right << std::setw(10) << cuaderno.contacts[i].get_last_name();
				std::cout << "|";
				if (cuaderno.contacts[i].get_nickname().length() > 10)
					std::cout << cuaderno.contacts[i].get_nickname().substr(0, 9) << ".";
				else
					std::cout << std::right << std::setw(10) << cuaderno.contacts[i].get_nickname();
				std::cout << "|";
				if (cuaderno.contacts[i].get_phone().length() > 10)
					std::cout << cuaderno.contacts[i].get_phone().substr(0, 9) << ".";
				else
					std::cout << std::right << std::setw(10) << cuaderno.contacts[i].get_phone();
				std::cout << "*" << std::endl;
			} */
			if (recorded != 0)
				cuaderno.print_table_tail();
			continue;
			// función mostrar lista resumida
			// pedir índice
			// mostrar contacto índice
		}
		else if (line == "EXIT")
		{
			std::cout << "ByeBye!!" << std::endl;
			break;
		}
		else if (std::cin.eof())
		{
			break;
		}
		else
		{
			std::cout << "Invalid command: ";
			std::cout << "ADD, SEARCH or EXIT" << std::endl;
		}
	}
	std::cin.clear();

	return 0;
}