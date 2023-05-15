#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "contact.hpp"

class Phonebook
{
public:
	Contact contacts[8];
	int		info_index;

	int		add_contact(int index);
	void	print_table_header() const;
	void	print_table_tail() const;
	void	print_table_body(int redorded) const;
	void	print_index_info(int index) const;
	int		select_index(int recorded) const;
};

#endif //PHONEBOOK_HPP