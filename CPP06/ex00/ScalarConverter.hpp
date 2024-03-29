#pragma once
# include "Automata.hpp"
# include <iostream>
# include <sstream>
# include <cmath>

# define MINUS 1
# define INT 2
# define CHAR 3
# define DOUBLE 4
# define FLOAT 5
# define STRING 6

class ScalarConverter
{
private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter& copy);
	ScalarConverter& operator=(const ScalarConverter& rhs);
	static bool check_special(std::string literal);
		
public:
	~ScalarConverter() {};
	static void convert(const std::string& literal);
};


int	get_type(const std::string& literal, Automata *a);