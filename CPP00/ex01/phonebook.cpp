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
		std::cout << "*" <<std::right << std::setw(10) << (i + 1) << "|";
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
		std::cout << "*" << std::endl;
	}
}

int	Phonebook::select_index(int recorded)
{
	int aux = 0;
	bool is_num = true;
	std::string buffer = "";

	while (buffer.length() == 0)
	{
		std::cout << "Select an index contact (1 to 8): " << std::endl;
		std::getline(std::cin, buffer);
		if (std::cin.eof())
		{
			std::cin.clear();
			return (1);
		}
	}
	for (std::string::size_type  i = 0; i < buffer.length(); i++)
	{
		if (!std::isdigit(buffer[i]))
		{
			is_num = false;
			break;
		}
	}
	if (is_num == true)
	{
		aux = std::stoi(buffer);
	}
	if (aux >= 1 && aux <= 8 && aux > recorded)
	{
		std::cout << "Registry " << aux << " is empty" << std::endl;	
		return (0);
	}	
	else if (aux >= 1 && aux <= 8)
		return (aux);
	else
		return (-1);	
}

void	Phonebook::print_index_info(int index)
{
	std::cout << "First Name: " << this->contacts[index - 1].get_first_name() << std::endl;
	std::cout << "Last Name: " << this->contacts[index - 1].get_last_name() << std::endl;
	std::cout << "Nickname: " << this->contacts[index - 1].get_nickname() << std::endl;
	std::cout << "Phone number: " << this->contacts[index - 1].get_phone() << std::endl;
	std::cout << "Darkest Secret: " << this->contacts[index - 1].get_secret() << std::endl;

}