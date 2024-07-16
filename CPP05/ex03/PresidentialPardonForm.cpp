# include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
{}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : 
	AForm("Presidential Pardon Form", 25, 5), _target(target)
{}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & copy) :
AForm(copy), _target(copy._target)
{}

PresidentialPardonForm::~PresidentialPardonForm()
{}

PresidentialPardonForm& PresidentialPardonForm::operator=(PresidentialPardonForm const & rhs)
{
	if (this != &rhs)
	{
		this->_target = rhs._target;
	}
	return (*this);
}

std::string PresidentialPardonForm::getTarget() const
{
	return (this->_target);
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (this->getSigned() == false)
		throw AForm::UnsignedForm();
	if (executor.getGrade() > this->getExecGrade())
	{
		std::cout << executor.getName() << " couldn't execute Presidential Pardon Form because ";
		throw AForm::GradeTooLowException();
	}
    std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
	
}
