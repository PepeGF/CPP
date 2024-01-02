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

bool ScalarConverter::check_special(std::string literal)
{
	std::string pseudoLiterals[6] = {"-inf", "inf", "nan", "-inff", "inff", "nanf"};
	for (int i = 0; i < 3; i++)
	{
		if (literal == pseudoLiterals[i])
		{
			std::cout << "char: immpossible\n" << "int: impossible" << std::endl;
			std::cout << "float: " << pseudoLiterals[i] << "f" << std::endl;
			std::cout << "double: " << pseudoLiterals[i] << std::endl;
			return true;
		}
	}
	for (int i = 3; i < 6; i++)
	{
		if (literal == pseudoLiterals[i])
		{
			std::cout << "char: immpossible\n" << "int: impossible" << std::endl;
			std::cout << "float: " << pseudoLiterals[i] << std::endl;
			std::cout << "double: " << pseudoLiterals[i].substr(0, (pseudoLiterals[i][0] == '-') ? 4 : 3) << std::endl;
			return true;
		}
	}
	return false;
}

void ScalarConverter::convert(const std::string& literal)
{
	// special cases
	if (check_special(literal) == true)
		return ;

	//primero hay que pasarlo a número y de ahí se castea a lo q corresponda
	
	// char cases
	std::cout << "Longitud: " << literal.length() << std::endl;
	if (literal.length() == 1 && isprint(literal[0]) && isdigit(literal[0]) == false)
	{
		std::cout << "char: " << literal[0] << std::endl;
		std::cout << "int: " << static_cast<int>(literal[0]) << std::endl;
		std::cout << "float: " << static_cast<float>(literal[0]) << std::endl;
		std::cout << "double: " << static_cast<double>(literal[0]) << std::endl;
		return ;	
	}
	if (literal.length() == 1 && isprint(literal[0]) == false /* && isdigit(literal[0]) == true */)
	{
		std::cout << "char: Non displayable" << std::endl;
		std::cout << "int: " << static_cast<int>(literal[0]) << std::endl;
		std::cout << "float: " << static_cast<float>(literal[0]) << std::endl;
		std::cout << "double: " << static_cast<double>(literal[0]) << std::endl;
		return ;
	}
	if (literal.length() <= 1 /* && isprint(literal[0]) == false */)
	{
		std::cout << "char: Non displayableeeeee" << std::endl;
		std::cout << "int: " << static_cast<int>(literal[0]) << std::endl;
		std::cout << "float: " << static_cast<float>(literal[0]) << std::endl;
		std::cout << "double: " << static_cast<double>(literal[0]) << std::endl;
		return ;
	}
	// float number
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