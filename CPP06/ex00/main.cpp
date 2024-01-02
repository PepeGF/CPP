# include <iostream>
# include <limits>
# include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
	/* int num = 42;
	(void)num;
	// float fl = static_cast<float>(num);
	float fl = 42.3f;

	std::cout << fl << "\n\n\n\n" <<  std::endl;


	float infFloat = std::numeric_limits<float>::infinity();
    float negInfFloat = -std::numeric_limits<float>::infinity();
    float nanFloat = std::numeric_limits<float>::quiet_NaN();

    std::cout << "float: inf = " << infFloat << std::endl;
    std::cout << "float: -inf = " << negInfFloat << std::endl;
    std::cout << "float: nan = " << nanFloat << std::endl;

    double infDouble = std::numeric_limits<double>::infinity();
    double negInfDouble = -std::numeric_limits<double>::infinity();
    double nanDouble = std::numeric_limits<double>::quiet_NaN();

    std::cout << "double: inf = " << infDouble << std::endl;
    std::cout << "double: -inf = " << negInfDouble << std::endl;
    std::cout << "double: nan = " << nanDouble << std::endl;
	 */
	if (argc < 2)
	{
		std::cout << "error: wrong arguments. \nUsage: ./convert <argument>" << std::endl;
		return (1);
	}
	ScalarConverter::convert(static_cast<std::string>(argv[1]));
	// std::cout << static_cast<int>(argv[1][0]) << std::endl;
	// std::cout << static_cast<float>(static_cast<int>(argv[1][0])) << std::endl;
	// std::cout << static_cast<double>(static_cast<int>(argv[1][0])) << std::endl;
	return (0);
}
