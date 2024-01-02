/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcauchet <jcauchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 15:30:24 by juliencauch       #+#    #+#             */
/*   Updated: 2022/10/14 19:46:42 by jcauchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	ShrubberyCreationForm fourty_two("42", "garden");
	Bureaucrat tac("Tac", 138);
	tac.signForm(fourty_two);
	std::cout << "There's an error because Tac grade is 138 and required grade for execution is 137 or less\n";
	tac.executeForm(fourty_two);
	tac.incrementGrade(100);
	tac.executeForm(fourty_two);

	std::cout << std::endl;
	ShrubberyCreationForm fourty_one("41", "bocal");
	Bureaucrat yoshi("Yoshi", 144);
	yoshi.signForm(fourty_two);
	yoshi.executeForm(fourty_two);
	
	std::cout << std::endl;
	RobotomyRequestForm fourty_three("43", "clusters");
	Bureaucrat palmi("Palmi", 73);
	palmi.signForm(fourty_three);
	palmi.incrementGrade(30);
	palmi.signForm(fourty_three);
	palmi.executeForm(fourty_three);

	std::cout << std::endl;
	PresidentialPardonForm fourty_four("44", "cafet");
	Bureaucrat mel("Mel", 5);
	mel.signForm(fourty_four);
	mel.executeForm(fourty_four);
}
