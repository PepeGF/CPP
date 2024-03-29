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
	int type;
	Automata* a = new (Automata);

	type = get_type(literal, a);
	if (type == MINUS || type == CHAR)
		std::cout << "I'm a char" << std::endl;
	if (type == INT)
		std::cout << "I'm an int, check overflow please" << std::endl;
	if (type == DOUBLE)
		std::cout << "I'm a double" << std::endl;
	if (type == FLOAT)
		std::cout << "I'm a float" << std::endl;
	if (type == STRING)
	{
		std::cout << "I'm a string" << std::endl;
		if (check_special(literal) == true)
			return ;
	}
	delete a;	
}


int	get_type(const std::string& literal, Automata *a)
{
	a->set_string(literal);
	return a->get_state();
}
