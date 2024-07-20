# pragma once

# include <ostream>

struct Data
{
	unsigned long int num;
};

std::ostream& operator<<(std::ostream& os, Data const & data);