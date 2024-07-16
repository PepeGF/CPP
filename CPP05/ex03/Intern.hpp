#pragma once
# include <iostream>
# include "AForm.hpp"
# include "Bureaucrat.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern
{
private:
	
public:
	Intern();
	Intern(Intern const & copy);
	~Intern();

	Intern& operator=(Intern const & rhs);
	
	AForm* ShrubberyForm(std::string target);
	AForm* RobotomyForm(std::string target);
	AForm* PresidentialForm(std::string target);
	AForm* makeForm(std::string form_name, std::string target);
};