/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcauchet <jcauchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 19:08:21 by jcauchet          #+#    #+#             */
/*   Updated: 2022/09/28 20:41:35 by jcauchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"

int	main(void)
{
	int	i = 0;
	std::string str;
	PhoneBook	phonebook;
	
	phonebook.init_contacts();
	while (1)
	{
		if (i == 8)
			i = 0;
		std::cout << "👉 \033[1;37mPlease enter a command:\033[0m" << std::endl;
		getline(std::cin, str);
		if (std::cin.eof())
			return 0;
		if (!str[0])
			continue;
		if (!strcmp(&str[0], "ADD"))
			phonebook.add_contact(&i);
		else if (!strcmp(&str[0], "SEARCH"))	
			phonebook.search_contact();
		else if (!strcmp(&str[0], "EXIT"))
			phonebook.exit_phonebook();
	}
}
