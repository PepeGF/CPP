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


	// char cases
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
	// std::cout << "Longitud: " << literal.length() << std::endl;

	int literal_size = literal.length();
	std::string str_base;
	if (literal[literal_size - 1] == 'f')
		str_base = literal.substr(0, literal_size - 1);
	else
		str_base = literal;

	double doublee;
	std::istringstream str_to_double(str_base); // un comentario.
	if (!(str_to_double >> doublee).fail())
	{
		if (doublee >= 32 && doublee <= 126)
		{
			std::cout << "char: '" << static_cast<char>(doublee) << "'" << std::endl;
		}
		else
		{
			std::cout << "char: non displayable" << std::endl;
		}
	}

	std::cout << "String base: " << str_base << std::endl;
/* 
	//primero hay que pasarlo a número y de ahí se castea a lo q corresponda
	std::cout << "Float: " << sizeof(float) << "\nDouble: " << sizeof(double) <<
	"\nInt: " << sizeof(int) <<  std::endl;
	// float number
	// int number = 42;
	int number = std::atoi(literal.c_str());
	std::cout << number << std::endl;
	// float num = 42.f;
	int num = std::atof(literal.c_str());
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
 */

	return ;
}