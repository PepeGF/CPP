#include "phonebook.hpp"
#include "contact.hpp"

int main()
{
	Phonebook cuaderno;
	std::int8_t index;
	std::string	line;

	while (std::getline(std::cin, line))
	{
		if (line == "ADD")
		{
			continue;
			// añadir contacto
		}
		else if (line == "SEARCH")
		{
			continue;
			// función mostrar lista resumida
			// pedir índice
			// mostrar contacto índice
		}
		else if (line == "EXIT")
		{
			// print EXIT
			break;
		}
		else if (std::cin.eof())
		{
			break;
		}
	}
	std::cin.clear();


	index = 3;
	cuaderno.add_contact(index);
	std::cout << cuaderno.contacts[index].first_name << std::endl;

	return 0;
}