# include "RobotomyRequestForm.hpp"
# include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm()
{}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : 
	AForm("Robotomy Form", 72, 45), _target(target)
{}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & copy) :
AForm(copy), _target(copy._target)
{}

RobotomyRequestForm::~RobotomyRequestForm()
{}

RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm const & rhs)
{
	if (this != &rhs)
	{
		this->_target = rhs._target;
	}
	return (*this);
}

std::string RobotomyRequestForm::getTarget() const
{
	return (this->_target);
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (this->getSigned() == false)
		throw AForm::GradeTooLowException();
	if (executor.getGrade() > this->getExecGrade())
		throw AForm::GradeTooLowException();

	std::cout << "BrrRrRrrrrrrr... brRRrrrRRr..." << std::endl;
	int success = std::rand() % 2;
	if (success == 1)
	{
		std::cout << this->getTarget() << " successfully robotomized!!!" << std::endl;
	}
	else
	{
		std::cout << this->getTarget() << " haven't been robotomized... so lucky" << std::endl;
	}
}
