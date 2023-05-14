#include "contact.hpp"

std::string Contact::_fill_buffer(std::string field)
{
	std::string buffer;

	std::cout << "Insert " << field << ": ";
	std::getline(std::cin, buffer);
	if (std::cin.eof())
	{
		std::cin.clear();
		std::cout << std::endl;
		return ("");
	}
	while (buffer.length() == 0)
	{
		std::cout << "This field can't be empty" \
		<< std::endl << "Insert " << field << ": ";
		std::getline(std::cin, buffer);
		if (std::cin.eof())
		{
			std::cin.clear();
			return ("");
		}
	}
	return (buffer);
}

int	Contact::add_contact()
{
	std::string	buffer;
	Contact		aux;

	this->_first_name = _fill_buffer("First Name");
	if (this->_first_name == "")
		return (1);
	this->_last_name = _fill_buffer("Last Name");
	if (this->_last_name == "")
		return (1);
	this->_nickname = _fill_buffer("Nickname");
	if (this->_nickname == "")
		return (1);
	this->_phone_number = _fill_buffer("Phone Number");
	if (this->_phone_number == "")
		return (1);
	this->_darkest_secret = _fill_buffer("Darkest Secret");
	if (this->_darkest_secret == "")
		return (1);
	
	return (0);
}

std::string Contact::get_first_name()
{
	return(this->_first_name);
}

std::string Contact::get_last_name()
{
	return(this->_last_name);
}

std::string Contact::get_nickname()
{
	return(this->_nickname);
}

std::string Contact::get_phone()
{
	return(this->_phone_number);
}

std::string Contact::get_secret()
{
	return(this->_darkest_secret);
}