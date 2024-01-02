/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcauchet <jcauchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 22:44:45 by juliencauch       #+#    #+#             */
/*   Updated: 2022/10/14 15:28:49 by jcauchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : Form("Unknown", 145, 137), _target("default") {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string name, std::string target) : Form(name, 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &src) : Form(src) {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &rhs)
{
	if (this != &rhs)
	{
		Form::operator=(rhs);
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void	ShrubberyCreationForm::execAction() const
{
	std::ofstream file((this->_target + "_shrubbery").c_str());
	
	for (int i = 0; i < 3; i++)
	{
		file << "      /\\      " << "\n";
		file << "     /\\/\\     " << "\n";
		file << "    /\\/\\/\\    " << "\n";
		file << "   /\\/\\/\\/\\   " << "\n";
		file << "  /\\/\\/\\/\\/\\  " << "\n";
		file << " /\\/\\/\\/\\/\\/\\ " << "\n";
		file << "/\\/\\/\\/\\/\\/\\/\\" << "\n";
		file << "      ||      " << "\n";
		file << "      ||      " << "\n";
		file << "      ||      " << "\n\n\n";
	}
	file.close();	
}

void	ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	Form::execute(executor);
	execAction();
}
