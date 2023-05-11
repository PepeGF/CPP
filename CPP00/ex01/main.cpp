#include "phonebook.hpp"
#include "contact.hpp"

int main()
{
	Phonebook cuaderno;
	static int index = 0;
	std::string	line;

	while (true)
	{
		std::cout << "Insert your command, please: " << std::endl;
		std::getline(std::cin, line);
		if (line == "ADD")
		{
			if (cuaderno.add_contact(index) == 2)
				//mensaje de error y salir
			continue;
			// añadir contacto
		}
		else if (line == "SEARCH")
		{
			std::cout << "Searching..." << std::endl;
			cuaderno.print_table_header();
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