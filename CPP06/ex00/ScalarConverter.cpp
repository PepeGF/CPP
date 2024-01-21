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
	/* if (literal.length() == 1 && isprint(literal[0]) && isdigit(literal[0]) == false)
	{
		std::cout << "char: " << literal[0] << std::endl;
		std::cout << "int: " << static_cast<int>(literal[0]) << std::endl;
		std::cout << "float: " << static_cast<float>(literal[0]) << std::endl;
		std::cout << "double: " << static_cast<double>(literal[0]) << std::endl;
		return ;	
	}
	if (literal.length() == 1 && isprint(literal[0]) == false ( && isdigit(literal[0]) == true ))
	{
		std::cout << "char: Non displayable" << std::endl;
		std::cout << "int: " << static_cast<int>(literal[0]) << std::endl;
		std::cout << "float: " << static_cast<float>(literal[0]) << std::endl;
		std::cout << "double: " << static_cast<double>(literal[0]) << std::endl;
		return ;
	}
	if (literal.length() <= 1 ( && isprint(literal[0]) == false) )
	{
		std::cout << "char: Non displayableeeeee" << std::endl;
		std::cout << "int: " << static_cast<int>(literal[0]) << std::endl;
		std::cout << "float: " << static_cast<float>(literal[0]) << std::endl;
		std::cout << "double: " << static_cast<double>(literal[0]) << std::endl;
		return ;
	} 
	*/
	// std::cout << "Longitud: " << literal.length() << std::endl;

	int literal_size = literal.length();
	std::string str_base;
	if (literal[literal_size - 1] == 'f')
		str_base = literal.substr(0, literal_size - 1);
	else
		str_base = literal;

	if (literal.length() == 1 && std::isprint(literal[0]) && !std::isdigit(literal[0]))
		std::cout << "char: " << literal[0] << std::endl;
	else
	{
		double doublee;
		std::istringstream check_char(str_base);
		if (!(check_char >> doublee).fail()) //empieza por algo q puede ser double
		{
			std::string buff;
			std::getline(check_char, buff);
			if (buff.empty()) //solo el double
			{
				int aux = static_cast<int>(doublee);
				if (aux >= 32 && aux <= 126)
					std::cout << "char: '" << static_cast<char>(aux) << "'" << std::endl;
				else
					std::cout << "char: Non displayable" << std::endl; 
			}
			else  //numeros y algo más
				std::cout << "char: impossible" << std::endl;
		}
		else //no es numero ni de coña
			std::cout << "char: impossible" << std::endl;
	}

	std::istringstream check_int(str_base);
	int integer;
	if (!(check_int >> integer).fail()) // puede ser un int si no hay nada más
	{
		std::string buff;
		std::getline(check_int, buff);
		if (buff.empty())
			std::cout << "int: " << integer << std::endl;
		else
			std::cout << "int: impossible" << std::endl;
	}
	else
		std::cout << "int: impossible" << std::endl;

	std::istringstream check_float(str_base);
	float floatt;
	if (!(check_float >> floatt).fail())
	{
		std::string buff;
		std::getline(check_int, buff);
		if (buff.empty())
		{
			if (std::floor(floatt) == floatt)
				std::cout  << "float: " << floatt << ".0f" << std::endl;
			else
				std::cout  << std::fixed << "float: " << floatt << "f" << std::endl;
		}
		else
			std::cout << "float: impossible" << std::endl;
	}
	else
		std::cout << "float: impossible" << std::endl;

	std::istringstream check_double(str_base);
	double doublee;
	if (!(check_double >> doublee).fail())
	{
		std::string buff;
		std::getline(check_double, buff);
		if (buff.empty())
		{
			if (std::floor(doublee) == doublee)
				std::cout << "double: " << doublee << ".0" << std::endl;
			else
				std::cout << std::fixed << "double: " << doublee << std::endl;
		}
		else
			std::cout << "double: impossible" << std::endl;
	}
	else
		std::cout << "double: impossible" << std::endl;

	return ;
}