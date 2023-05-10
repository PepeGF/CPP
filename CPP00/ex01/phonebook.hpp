#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "contact.hpp"

class Phonebook
{
private:

	/* data */

public:
	Contact contacts[8];

	Phonebook(/* args */);
	~Phonebook();

	void	add_contact(std::int8_t index);
};




#endif