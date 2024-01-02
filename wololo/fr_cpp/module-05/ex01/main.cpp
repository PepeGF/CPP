/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcauchet <jcauchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 15:30:24 by juliencauch       #+#    #+#             */
/*   Updated: 2022/10/14 19:42:16 by jcauchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	try
	{
		Form TooHigh("TooHigh", 151, 0);
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
	Form Document("Document", 15, 15);
	std::cout << Document;
	Bureaucrat Tac("Tac", 16);
	std::cout << Tac;
	Tac.signForm(Document);
	Tac.incrementGrade(1);
	std::cout << Tac;
	Tac.signForm(Document);
	std::cout << Document;
	return 0;
}
