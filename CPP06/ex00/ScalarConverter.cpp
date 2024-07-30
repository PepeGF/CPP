# include "ScalarConverter.hpp"
# include "Automata.hpp"


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
	int type;
	Automata* a = new (Automata);

	type = get_type(literal, a);
	if (type == MINUS || type == CHAR)
		char_conversion(literal);
	if (type == INT)
		int_conversion(literal);
	if (type == DOUBLE)
		double_conversion(literal);
	if (type == FLOAT)
		float_conversion(literal);
	if (type == STRING)
	{
		if (check_special(literal) == true)
			return ;
		other_conversion();
	}
	delete a;	
}

int	get_type(const std::string& literal, Automata *a)
{
	a->set_string(literal);
	return a->get_state();
}

void	char_conversion(const std::string& literal)
{
	if (literal[0] >= ' ' || literal[0] <= '~')
		std::cout << "char: '" << literal[0] << "'" << std::endl;
	else
		std::cout << "char: not displayable" << std::endl;
	int aux;
	aux = static_cast<int>(literal[0]);
	float auxf;
	auxf = static_cast<float>(literal[0]);
	double auxd;
	auxd = static_cast<double>(literal[0]);
	std::cout << "int: " << aux << std::endl;
	std::cout << "float: " << auxf << ".0f" << std::endl;
	std::cout << "double: " << auxd << ".0" << std::endl;
}

void	int_conversion(const std::string& literal)
{
	long int aux;

	aux = atol(literal.c_str());
	if (aux > __INT_MAX__ || aux < -__INT_MAX__ - 1)
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: int overflow" << std::endl;
	}
	else
	{
		std::cout << "char: " << static_cast<char>(aux) << std::endl;
		std::cout << "int: " << atoi(literal.c_str()) << std::endl;
	}
		std::cout << "float: " << static_cast<float>(aux) << ".0f" << std::endl;
		std::cout << "double: " << static_cast<double>(aux) << ".0" << std::endl;
}

void	double_conversion(const std::string& literal)
{
	long double aux;

	aux = strtold(literal.c_str(), NULL);
	if (aux >= 0 && aux <= 255)
	{
		if (aux >= 32 && aux <= 126)
			std::cout << "char: " << static_cast<char>(aux) << std::endl;
		else
			std::cout << "char: not printable" << std::endl;
		std::cout << "int: " << static_cast<int>(aux) << std::endl;
	}
	else
	{
		std::cout << "char: impossible" << std::endl;
		if (aux < __INT_MAX__ && aux > -__INT_MAX__ - 1)
			std::cout << "int: " << static_cast<int>(aux) << std::endl;
		else
			std::cout << "int: overflow" << std::endl;
	}
	std::cout << "float: " << static_cast<float>(aux) << "f" << std::endl;
	std::cout << "double: " << literal << std::endl;
}

void float_conversion(const std::string& literal)
{
	float aux;

	aux = strtof(literal.c_str(), NULL);
	if (aux >= 0 && aux <= 255)
	{
		if (aux >= 32 && aux <= 126)
			std::cout << "char: " << static_cast<char>(aux) << std::endl;
		else
			std::cout << "char: not printable" << std::endl;
		std::cout << "int: " << static_cast<int>(aux) << std::endl;
	}
	else
	{
		std::cout << "char: impossible" << std::endl;
		if (aux < static_cast<float>(__INT_MAX__) 
			&& aux > static_cast<float>(-__INT_MAX__ - 1))
			std::cout << "int: " << static_cast<int>(aux) << std::endl;
		else
			std::cout << "int: overflow" << std::endl;
	}
	std::cout << "float: " << aux << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(aux) << std::endl;
}

bool check_special(std::string literal)
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

void other_conversion()
{
	std::cout << "char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible"
				<< std::endl;
}

