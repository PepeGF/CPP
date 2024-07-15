# include "Form.hpp"

Form::Form() : _name("Very special form"), _signed(false), _sign_grade(10), _exec_grade(1)
{
	if (_sign_grade < 1 || _exec_grade < 1)
		throw Form::GradeTooHighException();
	if (_sign_grade > 150 || _exec_grade > 150)
		throw Form::GradeTooLowException();
	std::cout << "Form default constructor called" << std::endl;
}

Form::Form(std::string name, int sign_grade, int exec_grade) :
	_name(name), _signed(false), _sign_grade(sign_grade), _exec_grade(exec_grade)
{
	if (_sign_grade < 1 || _exec_grade < 1)
		throw Form::GradeTooHighException();
	if (_sign_grade > 150 || _exec_grade > 150)
		throw Form::GradeTooLowException();
	std::cout << "Form parametrized constructor called" << std::endl;
}

Form::Form(Form const & copy) :
	_name(copy._name), _signed(copy._signed), _sign_grade(copy._sign_grade), _exec_grade(copy._exec_grade)
{
	if (_sign_grade < 1 || _exec_grade < 1)
		throw Form::GradeTooHighException();
	if (_sign_grade > 150 || _exec_grade > 150)
		throw Form::GradeTooLowException();
	std::cout << "Form copy constructor called" << std::endl;
}

Form::~Form()
{
	std::cout << "Form destructor called" << std::endl;
}

Form& Form::operator=(Form const & rhs)
{
	if (this != &rhs)
	{
		if (_sign_grade < 1 || _exec_grade < 1)
			throw Form::GradeTooHighException();
		if (_sign_grade > 150 || _exec_grade > 150)
			throw Form::GradeTooLowException();
		this->_signed = rhs._signed;
	}
	return *this;
}

std::string const Form::getName() const
{
	return (this->_name);
}
bool			Form::getSigned() const
{
	return (this->_signed);
}

int				Form::getSignGrade() const
{
	return (this->_sign_grade);
}

int				Form::getExecGrade() const
{
	return (this->_exec_grade);
}

void			Form::beSigned(Bureaucrat& vogon)
{
	if (vogon.getGrade() > this->_sign_grade)
		{
		std::cout << vogon.getName() << " couldn't sign "
			<< this->_name << " because ";
		throw Form::GradeTooLowException();
		}
	this->_signed = true;
	std::cout << vogon.getName() << " signed " << this->_name << std::endl;
}

const char* Form::GradeTooLowException::what() const throw ()
{
	return ("Grade too low");
}

const char* Form::GradeTooHighException::what() const throw ()
{
	return ("Grade too high");
}

std::ostream& operator<<(std::ostream& os, Form const & form)
{
	os << "Form name:\t" << form.getName() << "\n"
		<< "     signed:\t" << (form.getSigned() ? "Yes" : "No") << "\n"
		<< "sign grade:\t" << form.getSignGrade() << "\n"
		<< "exec grade:\t" << form.getExecGrade() << std::endl;
	return os;
}

