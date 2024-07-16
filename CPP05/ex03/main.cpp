# include <iostream>
# include "Bureaucrat.hpp"
# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "Intern.hpp"

int main()
{
	{
	try
	{
		Bureaucrat president("Zaphod Beeblebrox", 1);
		Bureaucrat secretary("Zaphod Beeblebrox", 1);
		Intern bob;
		AForm* form1;

		form1 = bob.makeForm("Presidential Pardon Form", "Homer Simpson");
		president.executeForm(*form1);
		delete form1;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	}{
	try
	{
	std::cout << "----------------------------------------------" << std::endl;
	{
		Bureaucrat president("Zaphod Beeblebrox", 1);
		Bureaucrat secretary("Zaphod Beeblebrox", 1);
		Intern bob;
		AForm* form1;

		form1 = bob.makeForm("Presidential Pardon Form", "Homer Simpson");
		form1->beSigned(secretary);
		president.executeForm(*form1);
		delete form1;
	}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	}{
	try{
	std::cout << "----------------------------------------------" << std::endl;
	{
		Bureaucrat president("Zaphod Beeblebrox", 1);
		Bureaucrat secretary("Major Quimby", 15);
		Intern bob;
		AForm* form1;

		form1 = bob.makeForm("Presidential Pardon Form", "Homer Simpson");
		form1->beSigned(secretary);
		president.executeForm(*form1);
		delete form1;
	}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	}{
	try
	{
	std::cout << "----------------------------------------------" << std::endl;
	{
		Bureaucrat president("Milei", 1);
		Bureaucrat secretary("K", 15);
		Intern bob;
		AForm* form1;

		form1 = bob.makeForm("Wololo Form", "Homer Simpson");
		if (form1 != NULL)
		{
			form1->beSigned(secretary);
			president.executeForm(*form1);
			delete form1;
		}
	}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	}{
	try
	{
	std::cout << "----------------------------------------------" << std::endl;
	{
		Bureaucrat president("Milei", 120);
		Bureaucrat secretary("Cristina K", 130);
		Intern bob;
		AForm* form1;

		form1 = bob.makeForm("Shrubbery Form", "Homer Simpson");
		if (form1 != NULL)
		{
			form1->beSigned(secretary);
			president.executeForm(*form1);
			delete form1;
		}
	}}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	}{
	try
	{
	std::cout << "----------------------------------------------" << std::endl;
	{
		Bureaucrat president("Milei", 120);
		Bureaucrat secretary("Cristina K", 130);
		Intern bob;
		AForm* form1;

		form1 = bob.makeForm("Robotomy Form", "Homer Simpson");
		if (form1 != NULL)
		{
			try
			{
				form1->beSigned(secretary);
				president.executeForm(*form1);
			}
			catch(const std::exception& e)
			{
				std::cerr << e.what() << '\n';
			}
			delete form1;
		}
	}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	}{
	try
	{
	std::cout << "----------------------------------------------" << std::endl;
	{
		Bureaucrat president("Milei", 120);
		Bureaucrat secretary("Cristina K", 130);
		Intern bob;
		AForm* form1;

		form1 = bob.makeForm("Other tipe of form", "Homer Simpson");
		if (form1 != NULL)
		{
			try
			{
				form1->beSigned(secretary);
				president.executeForm(*form1);
			}
			catch(const std::exception& e)
			{
				std::cerr << e.what() << '\n';
			}
			delete form1;
		}
	}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	}

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
