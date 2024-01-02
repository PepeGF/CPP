/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliencaucheteux <juliencaucheteux@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 15:24:06 by juliencauch       #+#    #+#             */
/*   Updated: 2022/10/13 20:19:30 by juliencauch      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Unknown"), _grade(150)
{
	std::cout << "Bureaucrat: Default constructor has been called and grade has been set to 150\n";
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	if (grade > 150)
		throw GradeTooLowException();
	else if (grade < 1) 
		throw GradeTooHighException();
	this->_grade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat const &src) : _name(src._name)
{
	*this = src;
}

Bureaucrat	&Bureaucrat::operator=(Bureaucrat const &rhs)
{
	if (this != &rhs)
		this->_grade = rhs._grade;
	return *this;
}

std::ostream &operator<<(std::ostream &o, Bureaucrat const &obj)
{
	o << obj.getName() << "'s grade value is " << obj.getGrade() << std::endl;
	return o;
}

Bureaucrat::~Bureaucrat() {}

// Grade operations

void	Bureaucrat::decrementGrade(unsigned int val)
{
	if (this->_grade + val > 150)
		throw GradeTooLowException();
	this->_grade += val;
}

void	Bureaucrat::incrementGrade(unsigned int val)
{
	if (this->_grade - val < 1)
		throw GradeTooHighException();
	this->_grade -= val;
}

// Accessors

std::string const Bureaucrat::getName() const
{
	return this->_name;
}

int Bureaucrat::getGrade() const
{
	return this->_grade;
}
