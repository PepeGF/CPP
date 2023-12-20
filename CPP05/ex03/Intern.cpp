# include "Intern.hpp"

Intern::Intern() : forms_made(0)
{}

Intern::Intern(Intern const & copy)
{
	*this = copy;
}

/* Intern::Intern()
{} */

Intern::~Intern()
{}

Intern& Intern::operator=(Intern const & rhs)
{
	if (this != &rhs)
	{
		*this = rhs;
	}
	return (*this);
}

AForm* Intern::makeForm(std::string form_name, std::string target)
{
	std::string forms[3] = {"Shrubbery Form", "Robotomy Form", "Presidential Pardon Form"};
	for (int i = 0; i < 3; i++)
	{
		if (form_name == forms[i])
		{
			std::cout << "Intern creates " << form_name << std::endl;
			switch (i)
			{
			case 0:
				return (new ShrubberyCreationForm(target));
			case 1:
				return (new RobotomyRequestForm(target));
			case 2:
				return (new PresidentialPardonForm(target));
			}
		}
	}
	std::cout << "Intern couldn't create the form" << std::endl;
	return (NULL);
}