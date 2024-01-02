/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcauchet <jcauchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 15:30:24 by juliencauch       #+#    #+#             */
/*   Updated: 2022/10/14 19:35:36 by jcauchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat Tac("Tac", 0);
	}
	catch (std::exception &e)
	{
		std::cout << "Tac grade is too low, exeception message is triggered\n";
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
	try
	{
		Bureaucrat Mel("Mel", 151);
	}
	catch(const std::exception& e)
	{
		std::cout << "Mel grade is too high, exeception message is triggered\n";
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
	try
	{
		Bureaucrat Yoshi("Yoshi", 1);
		std::cout << Yoshi;
		Yoshi.incrementGrade(1);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
	try
	{
		Bureaucrat Palmi("Palmi", 150);
		std::cout << Palmi;
		Palmi.decrementGrade(1);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl << "---Normal case---" << std::endl;
	try
	{
		Bureaucrat Test("Test", 42);
		std::cout << Test.getName() << " has grade " << Test.getGrade() <<std::endl;
		Test.incrementGrade(1);
		std::cout << Test.getName() << " has grade " << Test.getGrade() <<std::endl;
		Test.decrementGrade(1);
		std::cout << Test.getName() << " has grade " << Test.getGrade() <<std::endl;
	}
	catch(std::exception &e)
	{
		std::cout << "This will not be printed" << std::endl;
		std::cerr << e.what() << std::endl;
	}
	return 0;
}
