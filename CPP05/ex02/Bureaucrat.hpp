#pragma once
#include <iostream>
#include <exception>
#include "AForm.hpp"

class AForm;

class Bureaucrat
{
private:
	std::string const	_name;
	int					_grade;

public:
	Bureaucrat();
	Bureaucrat(std::string name, int grade);
	Bureaucrat(Bureaucrat const & copy);
	~Bureaucrat();

	Bureaucrat& operator=(Bureaucrat const & rhs);

	std::string const getName(void) const;
	int			getGrade(void) const;
	void		incrementGrade(void);
	void		decrementGrade(void);
	void		signForm(AForm & form);
	void		executeForm(AForm const & form);

	class GradeTooHighException : virtual public std::exception
	{
		public:
			const char* what() const throw ();
	};

	class GradeTooLowException : virtual public std::exception
	{
		public:
			const char* what() const throw ();
	};
};

std::ostream& operator<<(std::ostream& os, Bureaucrat const & bureaucrat);
