#pragma once
# include <iostream>
# include <exception>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
	std::string const	_name;
	bool 				_signed;
	int const			_sign_grade;
	int const			_exec_grade;

public:
	Form();
	Form(std::string name, int sign_grade, int exec_grade);
	Form(Form const & copy);
	~Form();

	Form& operator=(Form const & rhs);

	std::string const getName() const;
	bool			getSigned() const;
	int				getSignGrade() const;
	int				getExecGrade() const;
	void			beSigned(Bureaucrat& vogon);

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
};

std::ostream& operator<<(std::ostream& os, Form const & form);