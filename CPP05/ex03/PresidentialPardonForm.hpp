#pragma once
#include "AForm.hpp"
#include <iostream>

class PresidentialPardonForm : public AForm
{
private:
	std::string _target;
	PresidentialPardonForm();

public:
	PresidentialPardonForm(std::string target);
	PresidentialPardonForm(PresidentialPardonForm const & copy);
	~PresidentialPardonForm();

	PresidentialPardonForm& operator=(PresidentialPardonForm const & rhs);

	std::string getTarget() const;
	void execute(Bureaucrat const & executor) const;
};