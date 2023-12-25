# include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{}

ScalarConverter::ScalarConverter(const ScalarConverter& copy)
{
	*this = copy;
}

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
	std::string pseudoLiterals[6] = {"-inf", "inf", "nan", "-inff", "inff", "nanf"};
	// char

	if (literal.length() == 1 && isprint(literal[0]) && isdigit(literal[0]) == 0)
		// is a char
	{
		std::cout << "char: " << literal[0] << std::endl;
		std::cout << "int: " << static_cast<int>(literal[0]) << std::endl;
		std::cout << "float: " << static_cast<float>(literal[0]) << std::endl;
		std::cout << "double: " << static_cast<double>(literal[0]) << std::endl;
		return ;	
	}
	int number = 42;
	number = std::atoi(literal.c_str());
	std::cout << number << std::endl;
	float num = 42.f;
	num = std::atof(literal.c_str());
	std::cout << num << std::endl;
	if (literal != "0" && literal !="0.0f" && literal != "0.f" && 
		literal != "-0" && literal != "+0" && num == 0)
	{

		std::cerr << "Literal " << literal << " is not convertible" << std::endl;
		// std::cout << literal[literal.size() - 1] << std::endl;
		return ;
	}
	if (literal[literal.size() - 1] == 'f')
	{
		std::cout << "termina en f" << std::endl;
	}
	// int
	// float
	// double


	return ;
}