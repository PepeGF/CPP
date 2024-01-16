#include <iostream>
# include <cstdlib>
# include <sstream>

class ScalarConverter
{
private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter& copy);
	ScalarConverter& operator=(const ScalarConverter& rhs);
	static bool check_special(std::string literal);
	
public:
	~ScalarConverter();
	static void convert(const std::string& literal);
};