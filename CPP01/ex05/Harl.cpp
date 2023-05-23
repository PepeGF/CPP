#include "Harl.hpp"

Harl::Harl()
{
	Harl::level_funct[0].level = "debug";
	Harl::level_funct[0].function = &Harl::debug;

	Harl::level_funct[1].level = "info";
	Harl::level_funct[1].function = &Harl::info;

	Harl::level_funct[2].level = "warning";
	Harl::level_funct[2].function = &Harl::warning;

	Harl::level_funct[3].level = "error";
	Harl::level_funct[3].function = &Harl::error;	
}

Harl::~Harl()
{}

void	Harl::debug(void)
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-" 
			<< "pickle- special-ketchup burger. I really do!"
			<< std::endl;
}

void	Harl::info(void)
{
	std::cout << "I cannot believe adding extra bacon costs more money. " 
			<< "You didn’t put enough bacon in my burger! If you did, "
			<< "I wouldn’t be asking for more!" 
			<< std::endl;
}

void	Harl::warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free. " 
			<< "I’ve been coming for years whereas you started working here "
			<< "since last month."
			<< std::endl;
}

void	Harl::error(void)
{
	std::cout << "This is unacceptable! I want to speak to the manager now."
			<< std::endl;
}

void	Harl::other(void)
{
	std::cout << "I complain about complain. This is a complaining inception"
			<< std::endl;
}

void Harl::complain(std::string level)
{
	void (Harl::*f)();
	int i;

	f = &Harl::other;
	for (i = 0; i <= 4; i++)
	{
		if (level_funct[i].level == level)
		{
			(this->*(level_funct[i].function))();
			return;
		}
	}
	(this->*f)();
}
