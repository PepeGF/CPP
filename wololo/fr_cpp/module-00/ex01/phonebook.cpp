/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcauchet <jcauchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 19:09:31 by jcauchet          #+#    #+#             */
/*   Updated: 2022/09/29 10:29:37 by jcauchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() {}
PhoneBook::~PhoneBook() {}

void	PhoneBook::init_contacts()
{
	for (int i = 0; i < 8; i++)
		this->contacts[i].init_one_contact();
}

void	PhoneBook::request_one_info(int *i, int type)
{
	std::string str;
	str[0] = 0;
	while (!str[0])
	{
		if (type == FIRST_NAME)
			std::cout << "👉 \033[1;37mFirst name\033[0m" << std::endl;
		else if (type == LAST_NAME)
			std::cout << "👉 \033[1;37mLast name\033[0m" << std::endl;
		else if (type == NICKNAME)
			std::cout << "👉 \033[1;37mNickname\033[0m" << std::endl;
		else if (type == DARKEST_SECRET)
			std::cout << "👉 \033[1;37mDarkest secret\033[0m" << std::endl;
		else
			std::cout << "👉 \033[1;37mPhone number\033[0m" << std::endl;
		getline(std::cin, str);
		if (std::cin.eof())
			exit(0);
		if (type == PHONE_NUMBER)
		{
			for (int i = 0; str[i]; i++)
			{
				if (!isdigit(str[i]))
				{
					std::cout << "❌ \033[1;31mPlease enter a valid phone number.\033[0m" << std::endl;
					str[0] = 0;
					break;
				}
		}
		}
		
	}
	if (type == FIRST_NAME)
		this->contacts[*i].set_info(str, FIRST_NAME);
	else if (type == LAST_NAME)
		this->contacts[*i].set_info(str, LAST_NAME);
	else if (type == NICKNAME)
		this->contacts[*i].set_info(str, NICKNAME);
	else if (type == DARKEST_SECRET)
		this->contacts[*i].set_info(str, DARKEST_SECRET);
	else
		this->contacts[*i].set_info(str, PHONE_NUMBER);
}

void	PhoneBook::add_contact(int *i)
{
	this->request_one_info(i, FIRST_NAME);
	this->request_one_info(i, LAST_NAME);
	this->request_one_info(i, NICKNAME);
	this->request_one_info(i, DARKEST_SECRET);
	this->request_one_info(i, PHONE_NUMBER);
	(*i)++;
}

void	PhoneBook::search_contact()
{
	std::string str;
	int	index;
	
	std::cout << std::endl << "\033[1;34m     index|first name| last name|  nickname\033[0m" << std::endl;
	for (int i = 0; i < 8; i++)
		if (this->contacts[i].print_contact_tab(i))
			break;
	std::cout << std::endl;
	std::cout << "👉 \033[1;37mIndex:\033[0m" << std::endl;
	getline(std::cin, str);
	if (std::cin.eof())
		exit(0);
	for (int i = 0; str[i]; i++)
	{
		if (!isdigit(str[i]))
		{
			std::cout << "❌ \033[1;31mBad index format.\033[0m" << std::endl;
			return ;
		}
	}
	index = atoi(&str[0]);
	if (index < 0 || index > 7)
	{
		std::cout << "❌ \033[1;31mError: bad index number.\033[0m" << std::endl;
		return;
	}
	this->contacts[index].print_contact();
}

void	PhoneBook::exit_phonebook()
{
	exit(0);
}
