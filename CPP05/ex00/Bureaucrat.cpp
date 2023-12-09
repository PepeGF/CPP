#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : 
	_name("Unknown bureaucrat"), _range(150)
{
	std::cout << "Unknown bureaucrat created with minimum grade" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int range) :
	_name(name), _range(range)
{
	if (range < 1)
		throw Bureaucrat::GradeTooHighException();
	if (range > 150)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& copy) : 
	_name(copy._name), _range(copy._range)
{}

Bureaucrat::~Bureaucrat()
{}


std::string Bureaucrat::getName(void) const
{
	return (this->_name);
}

int Bureaucrat::getGrade(void) const
{
	return (this->_range);
}

void Bureaucrat::incrementGrade(void)
{
	this->_range--;
}

void Bureaucrat::decrementGrade(void)
{
	this->_range++;
}

const char* Bureaucrat::GradeTooHighException::what(void) const throw ()
{
	return ("Error: Grade assigned to bureaucrat is too high.");
}

const char* Bureaucrat::GradeTooLowException::what(void) const throw ()
{
	return ("Error: Grade assigned to bureaucrat is too low.");
}

std::ostream& operator<<(std::ostream& os, Bureaucrat const & bureaucrat)
{
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return os;
}
