/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcauchet <jcauchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 17:02:24 by jcauchet          #+#    #+#             */
/*   Updated: 2022/10/14 19:59:56 by jcauchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern() {}

Intern::Intern(Intern const &src)
{
	*this = src;
}

Intern &Intern::operator=(Intern const &)
{
	return *this;
}

Form *Intern::makeForm(std::string name, std::string const target)
{
	std::string types[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	for (int i = 0; i < 3; i++)
	{
		if (name == types[i])
		{
			std::cout << "Intern creates " + types[i] + " form." << std::endl;
			switch (i)
			{
			case 0:
				return new ShrubberyCreationForm(name, target);
			case 1:
				return new RobotomyRequestForm(name, target);
			case 2:
				return new PresidentialPardonForm(name, target);
			}	
		}
	}
	std::cout << "Form name is incorrect\n";
	return NULL;
}

Intern::~Intern() {}
