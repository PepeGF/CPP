#pragma once
# include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
private:
	std::string _target;
	ShrubberyCreationForm();
	
public:
	ShrubberyCreationForm(std::string const target);
	ShrubberyCreationForm(ShrubberyCreationForm const & copy);
	~ShrubberyCreationForm();

	ShrubberyCreationForm& operator=(ShrubberyCreationForm const & rhs);

	void execute(Bureaucrat const & executor) const;

};


