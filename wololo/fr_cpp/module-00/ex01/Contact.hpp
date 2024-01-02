/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcauchet <jcauchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 19:06:21 by jcauchet          #+#    #+#             */
/*   Updated: 2022/09/28 19:00:33 by jcauchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

# define ADD 1
# define SEARCH 2
# define EXIT 3

# define FIRST_NAME 42
# define LAST_NAME 43
# define NICKNAME 44
# define DARKEST_SECRET 45
# define PHONE_NUMBER 46

class Contact
{
public:
	Contact();
	~Contact();
	void	init_one_contact();
	void	set_info(std::string, int info);
	void	print_contact();
	void	print_one_info(std::string str);
	int		print_contact_tab(int i);
private:
	std::string		first_name;
	std::string		last_name;
	std::string		nickname;
	std::string		darkest_secret;
	long long int	phone_number;
};
