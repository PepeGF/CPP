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

public:
	Harl();
	~Harl();
	void	complain(std::string level);
};

#endif
