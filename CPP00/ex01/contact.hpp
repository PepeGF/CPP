#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>

class Contact
{
private:

	std::string	_first_name;
	std::string _last_name;
	std::string _nickname;
	std::string _phone_number;
	std::string _darkest_secret;
	std::string _fill_buffer(std::string field);

	// static int	_cuantity;

public:

	// Contact();
	// ~Contact();

	int			add_contact(void);
	std::string	get_first_name() const;
	std::string get_last_name() const;
	std::string get_nickname() const;
	std::string get_phone() const;
	std::string get_secret() const;
};




#endif // CONTACT_HPP
