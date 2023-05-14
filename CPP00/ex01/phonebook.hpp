#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "contact.hpp"

class Phonebook
{
private:

	/* data */

public:
	Contact contacts[8];
	int		info_index;

	int		add_contact(int index);
	void	print_table_header();
	void	print_table_tail();
	void	print_table_body(int redorded);
	int		select_index(int recorded);
	void	print_index_info(int index);
};




#endif