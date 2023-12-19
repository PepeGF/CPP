# include <iostream>
# include "Bureaucrat.hpp"
# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "Intern.hpp"

int main()
{
	Intern lupinicio;
	AForm* random;
	(void) random;
	(void) lupinicio;

	lupinicio.makeForm("Shrubbery Form", "wololo");

/* 
	try
	{
		Bureaucrat onesiforo("Onesiforo", 30);
		ShrubberyCreationForm bush("George");
		RobotomyRequestForm robotomy("Clinton");
		PresidentialPardonForm presidential("Trump");

		onesiforo.signForm(bush);
		onesiforo.executeForm(bush);

		onesiforo.signForm(robotomy);
		onesiforo.executeForm(robotomy);

		onesiforo.signForm(presidential);
		onesiforo.executeForm(presidential);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	} */
	
	/* 
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
 */


	return 0;
}
