#include <iostream>
#include "Bureaucrat.hpp"
# include "AForm.hpp"

int main()
{
	try
	{
		Bureaucrat onesiforo("Onesiforo", 30);
		AForm form("Destroy Earth", 50, 40);

		std::cout << std::endl;
		std::cout << form << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "--------------------------------------------------" << std::endl;
	try
	{
		Bureaucrat onesiforo("Onesiforo", 30);
		AForm form("Destroy Earth", 50, 40);

		std::cout << std::endl;
		std::cout << form << std::endl;
		onesiforo.signForm(form);
		std::cout << form << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "--------------------------------------------------" << std::endl;
	Bureaucrat* onesiforo = new Bureaucrat("Onesiforo", 130);
	AForm* form = new AForm("Destroy Earth", 50, 40);
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
