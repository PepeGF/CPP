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
			std::cout << std::endl;
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
			if (recorded != 0)
				cuaderno.print_table_tail();
			cuaderno.info_index = cuaderno.select_index(recorded);
			if (cuaderno.info_index != -1 && cuaderno.info_index != 0)
				cuaderno.print_index_info(cuaderno.info_index);
			if (cuaderno.info_index == -1)
				std::cout << "Invalid index" << std::endl;
			continue;
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