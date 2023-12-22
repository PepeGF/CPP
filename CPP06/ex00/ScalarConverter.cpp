# include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{}

ScalarConverter::ScalarConverter(const ScalarConverter& copy)
{
	*this = copy;
}

ScalarConverter::~ScalarConverter()
{}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& rhs)
{
	if (this != &rhs)
	{
		*this = rhs;
	}
	return *this;
}

void ScalarConverter::convert(const std::string& literal)
{
	(void)literal;
	std::string pseudoLiterals[6] = {"-inf", "+inf", "nan", "-inff", "+inff", "nanf"};
	// char
	// int
	// float
	// double


	return ;
}