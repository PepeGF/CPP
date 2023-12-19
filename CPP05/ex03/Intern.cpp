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
	std::string forms[3] = {"nombre 1", "n 2", "n 3"};
	for (int i = 0; i < 3; i++)
	{
		if (form_name == forms[i])
		{
			//mensaje creación
			switch (i)
			{
			case 0:
				/* code new shrubbery*/
				break;
			case 1:
				//new robotomy
				break;
			case 2:
				//new presidential
				break;
			}
		}
	}
	std::cout << "Intern couldn't create the form" << std::endl;
	return (NULL);
}