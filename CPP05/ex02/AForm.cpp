# include "AForm.hpp"

AForm::AForm() : _name("Very special AForm"), _signed(false), _sign_grade(10), _exec_grade(1)
{
	if (_sign_grade < 1)
		throw AForm::GradeTooHighException();
	if (_sign_grade > 150)
		throw AForm::GradeTooLowException();
	// std::cout << "AForm default constructor called" << std::endl;
}

AForm::AForm(std::string name, int sign_grade, int exec_grade) :
	_name(name), _signed(false), _sign_grade(sign_grade), _exec_grade(exec_grade)
{
	if (_sign_grade < 1)
		throw AForm::GradeTooHighException();
	if (_sign_grade > 150)
		throw AForm::GradeTooLowException();
	// std::cout << "AForm parametrized constructor called" << std::endl;
}

AForm::AForm(AForm const & copy) :
	_name(copy._name), _signed(copy._signed), _sign_grade(copy._sign_grade), _exec_grade(copy._exec_grade)
{
	if (_sign_grade < 1)
		throw AForm::GradeTooHighException();
	if (_sign_grade > 150)
		throw AForm::GradeTooLowException();
	// std::cout << "AForm copy constructor called" << std::endl;
}

AForm::~AForm()
{
	// std::cout << "AForm destructor called" << std::endl;
}

AForm& AForm::operator=(AForm const & rhs)
{
	if (_sign_grade < 1)
		throw AForm::GradeTooHighException();
	if (_sign_grade > 150)
		throw AForm::GradeTooLowException();
	this->_signed = rhs._signed;
	// *this = rhs;
	return *this;
}

std::string const AForm::getName() const
{
	return (this->_name);
}
bool			AForm::getSigned() const
{
	return (this->_signed);
}

int				AForm::getSignGrade() const
{
	return (this->_sign_grade);
}

int				AForm::getExecGrade() const
{
	return (this->_exec_grade);
}

void			AForm::beSigned(Bureaucrat& vogon)
{
	if (vogon.getGrade() > this->_sign_grade)
		{
		std::cout << vogon.getName() << " couldn't sign "
			<< this->_name << " because ";
		throw AForm::GradeTooLowException();
		}
	this->_signed = true;
}

const char* AForm::GradeTooLowException::what() const throw ()
{
	return ("Grade too low");
}

const char* AForm::GradeTooHighException::what() const throw ()
{
	return ("Grade too high");
}

const char* AForm::UnsignedForm::what() const throw ()
{
	return ("Form unsigned");
}

const char* AForm::AlreadySignedException::what() const throw ()
{
	return ("Form is already signed");
}

std::ostream& operator<<(std::ostream& os, AForm const & AForm)
{
	os << "AForm name:\t" << AForm.getName() << "\n"
		<< "     signed:\t" << (AForm.getSigned() ? "Yes" : "No") << "\n"
		<< "sign grade:\t" << AForm.getSignGrade() << "\n"
		<< "exec grade:\t" << AForm.getExecGrade() << std::endl;
	return os;
}

