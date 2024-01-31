# pragma once
# include <iostream>

template<typename T>
class Array
{
private:
	T 				*_ptr;
	unsigned int	_size;
public:
	Array();
	Array(unsigned int size);
	Array(Array const &copy);
	~Array();

	Array &operator=(Array const &rhs);
	T &operator[](unsigned int index);

	unsigned int const &size() const;
};

#include "Array.tpp"
