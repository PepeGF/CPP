# include "Intern.hpp"

Intern::Intern()
{}

Intern::Intern(Intern const & copy)
{
	*this = copy;
}

Intern::Intern()
{}

Intern::~Intern()
{}

AForm* Intern::makeForm(std::string form_name, std::string target)
{
	AForm* forms[3] =
	{
		new ShrubberyCreationForm(target), new RobotomyRequestForm(target), new PresidentialPardonForm(target)
	};

	for (int i = 0; i < 3; i++)
	{
		if (forms[i]->getName() == form_name)
		{
			std::cout << "Intern creates " << form_name << std::endl;
			return forms[i];
		}
	}
	std::cout << "Intern couldn't create the form" << std::endl;
	return (NULL);
}