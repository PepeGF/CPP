#pragma once
# include <iostream>
# include <exception>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
private:
	std::string const	_name;
	bool 				_signed;
	int const			_sign_grade;
	int const			_exec_grade;

public:
	AForm();
	AForm(std::string name, int sign_grade, int exec_grade);
	AForm(AForm const & copy);
	virtual ~AForm();

	AForm& operator=(AForm const & rhs);

	std::string const getName() const;
	bool			getSigned() const;
	int				getSignGrade() const;
	int				getExecGrade() const;
	void			beSigned(Bureaucrat& vogon);

	virtual void execute(Bureaucrat const & executor) const = 0;

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

	class AlreadySignedException : virtual public std::exception
	{
		public:
			const char* what() const throw ();
	};

	class UnsignedForm : virtual public std::exception
	{
		public:
			const char* what() const throw ();
	};
};

std::ostream& operator<<(std::ostream& os, AForm const & form);
