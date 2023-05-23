#ifndef HARL_CPP
#define HARL_CPP

#include <iostream>

class Harl
{
private:
	void	debug(void);
	void	info(void);
	void	warning(void);
	void	error(void);
	void	other(void);

	typedef struct	s_level_function
	{
		std::string	level;
		void (Harl::*function)();
	}				t_level_function;

	t_level_function level_funct[4];

public:
	Harl(/* args */);
	~Harl();
	void	complain(std::string level);
};

#endif
