# pragma once
# include <iostream>
# include <sstream>
# include <stdint.h>
# include "Data.hpp"

class Serializer
{
private:
	Serializer();
	Serializer(Serializer const & copy);
	Serializer & operator=(Serializer const & rhs);
public:
	~Serializer();

	static uintptr_t serialize(Data *ptr);
	static Data* deserialize(uintptr_t raw);
	static unsigned long int checker(uintptr_t ptr);
};

