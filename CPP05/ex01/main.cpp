#include <iostream>
#include "Bureaucrat.hpp"
# include "Form.hpp"

int main()
{
	try
	{
		Bureaucrat onesiforo("Onesiforo", 30);
		Form form("Destroy Earth", 50, 40);

		std::cout << std::endl;
		std::cout << form << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "--------------------------------------------------" << std::endl;
	try
	{
		Bureaucrat onesiforo("Onesiforo", 30);
		Form form("Destroy Earth", 50, 40);

		std::cout << std::endl;
		std::cout << form << std::endl;
		onesiforo.signForm(form);
		std::cout << form << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "--------------------------------------------------" << std::endl;
	try
	{
		Bureaucrat onesiforo("Onesiforo", 30);
		Form form("Destroy Earth", 50, 40);

		std::cout << std::endl;
		std::cout << form << std::endl;
		onesiforo.signForm(form);
		onesiforo.signForm(form);
		std::cout << form << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "--------------------------------------------------" << std::endl;
	Bureaucrat* onesiforo = new Bureaucrat("Onesiforo", 130);
	Form* form = new Form("Destroy Earth", 50, 40);
	try
	{

		std::cout << std::endl;
		std::cout << *form << std::endl;
		onesiforo->signForm(*form);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	delete form;
	delete onesiforo;
	std::cout << "--------------------------------------------------" << std::endl;

	return 0;
}
