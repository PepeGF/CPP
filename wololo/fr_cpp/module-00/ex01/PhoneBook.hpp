/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcauchet <jcauchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 19:06:08 by jcauchet          #+#    #+#             */
/*   Updated: 2022/09/28 20:39:13 by jcauchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Contact.hpp"

class PhoneBook
{
public:
	PhoneBook();
	~PhoneBook();
	void	init_contacts();
	void	add_contact(int *i);
	void	request_one_info(int *i, int type);
	void	search_contact();
	void	exit_phonebook();
private:
	Contact	contacts[8];
};
