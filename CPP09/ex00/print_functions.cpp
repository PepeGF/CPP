# include "BitcoinExchange.hpp"

void print_output(std::string date, float input_value, float database_value)
{
	std::cout << date << " => " 
		<< input_value << " = "
		<< database_value * input_value
		<< std::endl;
}

void print_database(std::map<std::string, float> &database)
{
	std::map<std::string, float>::iterator it;

	for (it = database.begin(); it != database.end(); it++)
	{
		std::cout << it->first
			<< " : "
			<< std::fixed << std::setprecision(2) << it->second
			<< std::endl;
	}
}

int print_invalid_line(std::string error)
{
	std::cerr << error << std::endl;
	return INVALID_LINE;
}

int print_invalid_date(std::string date)
{
	std::cerr << "Error: bad input => " << date << std::endl;
	return INVALID_LINE;
}
