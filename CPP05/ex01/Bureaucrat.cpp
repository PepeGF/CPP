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
	std::cout << "Bureaucrat parametrized constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const & copy) : 
	_name(copy._name), _range(copy._range)
{
	std::cout << "Bureaucrat copy constructor called" << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat destructor called" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(Bureaucrat const & rhs)
{
	std::cout << "Bureaucrat assignation operator called" << std::endl;
	
	if (rhs._range < 1)
		throw Bureaucrat::GradeTooHighException();
	if (rhs._range > 150)
		throw Bureaucrat::GradeTooLowException();
	if (this != &rhs)
		this->_range = rhs._range;
	return *this;
}

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
	int aux;
	aux = _range - 1;
	if (aux < 1)
		throw Bureaucrat::GradeTooHighException();
	if (aux > 150)
		throw Bureaucrat::GradeTooLowException();
	this->_range = this->_range - 1;
}

void Bureaucrat::decrementGrade(void)
{
	int aux;
	aux = _range + 1;
	if (aux < 1)
		throw Bureaucrat::GradeTooHighException();
	if (aux > 150)
		throw Bureaucrat::GradeTooLowException();
	this->_range = this->_range + 1;
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
