#include <iostream>
#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat voldemort;
		Bureaucrat onesiforo("Onesiforo", 70);
		Bureaucrat filogonio(onesiforo);
		Bureaucrat hermenegilda("Hermenegilda", 150);
		hermenegilda = onesiforo;

		for (int i = 0; i < 42; i++)
			filogonio.decrementGrade();

		for (int i = 0; i < 5; i++)
			hermenegilda.incrementGrade();

		std::cout << "\n" << voldemort << std::endl;
		std::cout << onesiforo << std::endl;
		std::cout << filogonio << std::endl;
		std::cout << hermenegilda << "\n" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-" << std::endl;
	try
	{
		Bureaucrat onesiforo("Onesiforo", 0);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-" << std::endl;
	try
	{
		Bureaucrat onesiforo("Onesiforo", 1903);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-" << std::endl;
	try
	{
		Bureaucrat onesiforo_boss("Onesiforo", 10);
		for (int i = 0; i < 20; i++)
			onesiforo_boss.incrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-" << std::endl;
	try
	{
		Bureaucrat onesiforo_low("Onesiforo", 100);
		for (int i = 0; i < 60; i++)
			onesiforo_low.decrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return 0;
}
