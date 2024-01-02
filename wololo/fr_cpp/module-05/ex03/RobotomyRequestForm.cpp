/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcauchet <jcauchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 15:31:36 by jcauchet          #+#    #+#             */
/*   Updated: 2022/10/14 19:07:52 by jcauchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm() : Form("Unknown", 72, 45)
{
	setTarget("default");
}

RobotomyRequestForm::RobotomyRequestForm(std::string name, std::string target) : Form(name, 72, 45)
{
	setTarget(target);
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &src) : Form(src) {}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &rhs)
{
	if (this != &rhs)
	{
		Form::operator=(rhs);
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void	RobotomyRequestForm::execAction() const
{
	std::cout << "** Loud drill noises **" << std::endl;
	srand((unsigned int)time(NULL));
	int random = rand() % 2;
	std::cout << this->_target;
	random ? std::cout << " has been successfully robotomized" : std::cout << " couldn't be robotomized";
	std::cout << std::endl;
}

void	RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	Form::execute(executor);
	execAction();
}
