#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "contact.hpp"

class Phonebook
{
private:

	Contact _contacts[8];
	/* data */

public:

	Phonebook(/* args */);
	~Phonebook();

	void	add_contact();
};




#endif