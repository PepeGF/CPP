# include <iostream>
# include "Bureaucrat.hpp"
# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

int main()
{
	std::cout << "\n1111111111111111111111111111111111111111111\n" << std::endl;
	Bureaucrat president("Zaphod Beeblebrox", 1);
	AForm *form = NULL;
	try
	{
		form = new ShrubberyCreationForm("Retiro");
		president.signForm(*form);
		president.executeForm(*form);
		delete form;
		form = new RobotomyRequestForm("Homer Simpson");
		president.signForm(*form);
		president.executeForm(*form);
		delete form;
		form = new PresidentialPardonForm("Arthur Dent");
		president.signForm(*form);
		president.executeForm(*form);
		delete form;
	}
	catch(const std::exception& e)
	{
		delete form;
		std::cerr << e.what() << '\n';
	}
	std::cout << "\n2222222222222222222222222222222222222222222\n" << std::endl;
	Bureaucrat veryimportantbureaucrat("Jeltz", 23);
	try
	{
		form = new ShrubberyCreationForm("Magrathea");
		veryimportantbureaucrat.signForm(*form);
		veryimportantbureaucrat.executeForm(*form);
		delete form;
		form = new RobotomyRequestForm("Moe Szyslak");
		veryimportantbureaucrat.signForm(*form);
		veryimportantbureaucrat.executeForm(*form);
		delete form;
		form = new PresidentialPardonForm("Arthur Dent");
		veryimportantbureaucrat.signForm(*form);
		veryimportantbureaucrat.executeForm(*form);
		delete form;
	}
	catch(const std::exception& e)
	{
		delete form;
		std::cerr << e.what() << '\n';
	}
	std::cout << "\n3333333333333333333333333333333333333333333\n" << std::endl;
	Bureaucrat mostlyimportantbureaucrat("Jeltz", 33);
	try
	{
		form = new ShrubberyCreationForm("Tierra");
		mostlyimportantbureaucrat.signForm(*form);
		mostlyimportantbureaucrat.executeForm(*form);
		delete form;
		form = new RobotomyRequestForm("Montgomery Burns");
		mostlyimportantbureaucrat.signForm(*form);
		mostlyimportantbureaucrat.executeForm(*form);
		delete form;
		form = new PresidentialPardonForm("Tricia McMillan");
		mostlyimportantbureaucrat.signForm(*form);
		mostlyimportantbureaucrat.executeForm(*form);
		delete form;
	}
	catch(const std::exception& e)
	{
		delete form;
		std::cerr << e.what() << '\n';
	}
	std::cout << "\n4444444444444444444444444444444444444444444\n" << std::endl;
	Bureaucrat middlegradebureaucrat("Patty Bouvier", 60);
	try
	{
		form = new ShrubberyCreationForm("Springfield");
		middlegradebureaucrat.signForm(*form);
		middlegradebureaucrat.executeForm(*form);
		delete form;
		form = new RobotomyRequestForm("Maggie Simpson");
		middlegradebureaucrat.signForm(*form);
		middlegradebureaucrat.executeForm(*form);
		delete form;
		form = new PresidentialPardonForm("Deepthought");
		middlegradebureaucrat.signForm(*form);
		middlegradebureaucrat.executeForm(*form);
		delete form;
	}
	catch(const std::exception& e)
	{
		delete form;
		std::cerr << e.what() << '\n';
	}
	std::cout << "\n5555555555555555555555555555555555555555555\n" << std::endl;
	Bureaucrat lowgradebureaucrat("Shelma Bouvier", 100);
	try
	{
		form = new ShrubberyCreationForm("Shelbyville");
		lowgradebureaucrat.signForm(*form);
		lowgradebureaucrat.executeForm(*form);
		delete form;
		form = new RobotomyRequestForm("Bart Simpson");
		lowgradebureaucrat.signForm(*form);
		lowgradebureaucrat.executeForm(*form);
		delete form;
		form = new PresidentialPardonForm("Slartibartfast");
		lowgradebureaucrat.signForm(*form);
		lowgradebureaucrat.executeForm(*form);
		delete form;
	}
	catch(const std::exception& e)
	{
		delete form;
		std::cerr << e.what() << '\n';
	}
	std::cout << "\n6666666666666666666666666666666666666666666\n" << std::endl;
	Bureaucrat almostnoonegradebureaucrat("Albert Einstein", 140);
	try
	{
		form = new ShrubberyCreationForm("Springfield Primary School");
		almostnoonegradebureaucrat.signForm(*form);
		almostnoonegradebureaucrat.executeForm(*form);
		delete form;
		form = new RobotomyRequestForm("Apu Nahasapeemapetilon");
		almostnoonegradebureaucrat.signForm(*form);
		almostnoonegradebureaucrat.executeForm(*form);
		delete form;
		form = new PresidentialPardonForm("Marvin");
		almostnoonegradebureaucrat.signForm(*form);
		almostnoonegradebureaucrat.executeForm(*form);
		delete form;
	}
	catch(const std::exception& e)
	{
		delete form;
		std::cerr << e.what() << '\n';
	}
	std::cout << "\n7777777777777777777777777777777777777777777\n" << std::endl;
	Bureaucrat insignificantbureaucrat("Voldemort", 140);
	try
	{
		form = new ShrubberyCreationForm("Hogwarts");
		insignificantbureaucrat.signForm(*form);
		insignificantbureaucrat.executeForm(*form);
		delete form;
		form = new RobotomyRequestForm("Hans topo");
		insignificantbureaucrat.signForm(*form);
		insignificantbureaucrat.executeForm(*form);
		delete form;
		form = new PresidentialPardonForm("Bender");
		insignificantbureaucrat.signForm(*form);
		insignificantbureaucrat.executeForm(*form);
		delete form;
	}
	catch(const std::exception& e)
	{
		delete form;
		std::cerr << e.what() << '\n';
	}
	std::cout << "\n\n\n" << std::endl;
	return 0;
}
