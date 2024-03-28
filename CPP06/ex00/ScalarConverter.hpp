#pragma once
# include "Automata.hpp"
# include <iostream>
# include <sstream>
# include <cmath>

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