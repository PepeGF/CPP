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
	Intern();
	~Intern();

	Intern& operator=(Intern const & rhs);
	AForm* makeForm(std::string form_name, std::string target);
};