# include <iostream>
# include <limits>
# include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "error: wrong arguments. \nUsage: ./convert <argument>" << std::endl;
		return (1);
	}
	ScalarConverter::convert(static_cast<std::string>(argv[1]));
	return (0);
}