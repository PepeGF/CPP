/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcauchet <jcauchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 15:21:31 by juliencauch       #+#    #+#             */
/*   Updated: 2022/10/14 14:54:49 by jcauchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include "Form.hpp"

class Form;

class Bureaucrat
{
public:
	Bureaucrat();
	Bureaucrat(std::string name, int grade);
	~Bureaucrat();
	Bureaucrat(Bureaucrat const &src);
	Bureaucrat &operator=(Bureaucrat const &rhs);
	
	void	signForm(Form &obj) const;
	void	executeForm(Form const &form);
	
	// Accessors
	std::string const getName() const;
	int getGrade() const;
	
	// Grade operations
	void	incrementGrade(unsigned int val);
	void	decrementGrade(unsigned int val);
	
	// Nested classes for exceptions
	class GradeTooHighException : public std::exception
	{
	public:
		const char *what() const throw()
		{
			return "Bureaucrat: Grade is to HIGH! Value range: [1, 150]";
		}
	};
	class GradeTooLowException : public std::exception
	{
	public:
		const char *what() const throw()
		{
			return "Bureaucrat: Grade is to LOW! Value range: [1, 150]";
		}	
	};	
private:
	std::string const _name;
	int _grade;
};

std::ostream &operator<<(std::ostream &o, Bureaucrat const &obj);
