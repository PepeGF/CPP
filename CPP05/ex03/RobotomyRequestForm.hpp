#pragma once
# include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
private:
	std::string _target;
	RobotomyRequestForm();

public:
	RobotomyRequestForm(std::string target);
	RobotomyRequestForm(RobotomyRequestForm const & copy);
	~RobotomyRequestForm();

	RobotomyRequestForm& operator=(RobotomyRequestForm const & rhs);

	std::string getTarget() const;
	void execute(Bureaucrat const & executor) const;
};
