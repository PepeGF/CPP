#pragma once
# include "Automata.hpp"
# include <iostream>
# include <sstream>
# include <cmath>
# include <limits>

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
		
public:
	~ScalarConverter() {};
	static void convert(const std::string& literal);
};


int		get_type(const std::string& literal, Automata *a);
void	char_conversion(const std::string& literal);
void	int_conversion(const std::string& literal);
void	double_conversion(const std::string& literal);
void	float_conversion(const std::string& literal);
bool	check_special(std::string literal);
void	other_conversion();
