#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "contact.hpp"

class Phonebook
{
private:

	/* data */

public:
	Contact contacts[8];

	// Phonebook(/* args */);
	// ~Phonebook();

	int	add_contact(int index);
	void	print_table_header();
	void	print_table_tail();
	void	print_table_body(int redorded);
};




#endif