#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>


class Contact
{
private:

	std::string	_first_name;
	std::string _last_name;
	std::string _nickname;
	std::string _phone_number;
	std::string _darkest_secret;
	std::string _fill_buffer(std::string field);

public:

	int			add_contact(void);
	std::string	get_first_name();
	std::string get_last_name();
	std::string get_nickname();
	std::string get_phone();
	std::string get_secret();


	Contact();
	~Contact();

};




#endif // CONTACT_HPP
