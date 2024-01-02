/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcauchet <jcauchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 15:30:24 by juliencauch       #+#    #+#             */
/*   Updated: 2022/10/14 20:02:01 by jcauchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
	Intern mel;
	{
	// Tests wrong name
	Form *bocal = mel.makeForm("fake", "bocal");
	
	bocal = mel.makeForm("presidential pardon", "bocal");
	std::cout << *bocal;
	delete bocal;
	}	
	std::cout << "----------------------------------------------" << std::endl;
	{
	Form *bocal = mel.makeForm("robotomy request", "bocal");
	std::cout << *bocal;
	Bureaucrat tac("Tac", 1);
	tac.signForm(*bocal);
	tac.executeForm(*bocal);
	delete bocal;
	}
	std::cout << "----------------------------------------------" << std::endl;
	{
		Bureaucrat president("Zaphod Beeblebrox", 1);
		Intern bob;
		Form* form1;

		form1 = bob.makeForm("presidential pardon", "Manolo");
		form1->beSigned(president);
		president.executeForm(*form1);
		delete form1;
	}
}
