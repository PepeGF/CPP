# include "BitcoinExchange.hpp"

void    print_exchange(std::string input_file, std::map<std::string, float> &database)
{
	std::ifstream	input(input_file.c_str());
	std::string		line;
	std::string		date;
	std::map<std::string, float>::iterator it;
	std::pair<std::map<std::string, float>::iterator, bool> inserted;
	// float			conversion;
	float			input_value;
	std::getline(input, line);
	std::getline(input, line);
	while (line.empty() == false)
	{
		if (check_and_print_input_line(line) == LINE_OK)
		{
			input_value = atof(line.substr(VALUE_INI_INDEX).c_str());
			date = line.substr(INDEX_INI, LEN_DATE_STRING);
			it = database.find(date);
			if (it != database.end())
			{
				// valor en base de datos
				std::cout << date << " => " 
					<< input_value << " = "
					<< database[date] * input_value
					<< std::endl;
			}
			else
			{
				inserted = database.insert(std::pair<std::string, float>(date, 0));
				it = database.find(date);
				if (it != database.begin())
				{
					--it;
					std::cout << date << " => " 
					<< input_value << " = " 
 
					<< it->second * input_value 
					<< std::endl;
					database.erase(++it);
				}
				else
				{
					std::cout << date << " => " 
					<< input_value << " = "
					<< it->second * input_value 
					<< std::endl;
					
				}
				//key no encontrada en base de datos
			}
		}
		std::getline(input, line);
	}
	return ;
}

int check_and_print_input_line(std::string &line)
{
	if (validate_date(line) == INVALID_LINE)
		return INVALID_LINE;
	if (validate_separator(line) == INVALID_LINE)
		return INVALID_LINE;
	if (validate_value(line) == INVALID_LINE)
		return INVALID_LINE;
	return LINE_OK;
}

int validate_value(std::string &line)
{
	float			value;
	std::string		aux;
	int				dots_counter = 0;

	if (line.length() >= VALUE_INI_INDEX)
	{
		aux = line.substr(VALUE_INI_INDEX);
		for (unsigned long i = 0; i < aux.length(); i++)
		{
			if (isdigit(aux[i]) == false && aux[i] != '.')
			{
				std::cerr << "Error: invalid input." << std::endl;
				return INVALID_LINE;
			}
			if (aux[i] == '.')
			{
				dots_counter++;
				if (dots_counter > 1)
				{
					std::cerr << "Error: invalid input." << std::endl;
					return INVALID_LINE;
				}
			}
		}
		value = atof(aux.c_str());
		if (value < 0)
		{
			std::cerr << "Error: not a positive number." << std::endl;
			return INVALID_LINE;
		}
		if (value > 1000)
		{
			std::cerr << "Error: too large a number." << std::endl;
			return INVALID_LINE;
		}
	}
	return LINE_OK;
}

int validate_separator(std::string &line)
{
	std::string separator;
	std::string right_separator = " | ";

	separator = line.substr(SEPARATOR_INI_INDEX, SEPARATOR_LEN);
	if (separator != right_separator)
	{
		std::cerr << "Error: wrong separator" << std::endl;
		return INVALID_LINE;
	}
	return LINE_OK;
}

int validate_date(std::string &line)
{
	std::string date;
	int			year;
	int			month;
	int			day;
	(void)year;


	date = line.substr(INDEX_INI, LEN_DATE_STRING);
	if (date[FIRST_MINUS_INDEX] != '-' || date[SECOND_MINUS_INDEX] != '-')
	{
		std::cerr << "Error: bad input => " << date << std::endl;
		return INVALID_LINE;
	}
	for (int i = INDEX_INI; i < YEAR_LEN; i++)
	{
		if (isdigit(date[i]) == false)
		{
			std::cerr << "Error: bad input => " << date << std::endl;
			return INVALID_LINE;
		}
	}
	year = atoi(line.substr(YEAR_INI_INDEX, YEAR_LEN).c_str());
	for (int i = MONTH_INI_INDEX; i < MONTH_INI_INDEX + MONTH_LEN; i++)
	{
		if (isdigit(date[i]) == false)
		{
			std::cerr << "Error: bad input => " << date << std::endl;
			return INVALID_LINE;
		}
	}
	month = atoi(line.substr(MONTH_INI_INDEX, MONTH_LEN).c_str());
	if (month > 12)
	{
		std::cout << "Error: bad input => " << date << std::endl;
		return INVALID_LINE;
	}
	for (int i = DAY_INI_INDEX; i < DAY_INI_INDEX + DAY_LEN; i++)
	{
		if (isdigit(date[i]) == false)
		{
			std::cout << "Error: bad input => " << date << std::endl;
			return INVALID_LINE;
		}
		// std::cout << date[i];
	}
	day = atoi(line.substr(DAY_INI_INDEX, DAY_LEN).c_str());
	if (day > 31 || day < 1)
	{
		std::cerr << "Error: bad input => " << date << std::endl;
		return INVALID_LINE;
	}
	if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
	{
		std::cerr << "Error: bad input => " << date << std::endl;
		return INVALID_LINE;
	}
	if (month == 2 && day > 28)
	{
		std::cerr << "Error: bad input => " << date << std::endl;
		return INVALID_LINE;
	}
	return LINE_OK;
}


void create_database(std::map<std::string, float> &database)
{
	std::ifstream file;
	std::string line;
	open_file(file);
	fill_database(database, file);
}

void open_file(std::ifstream &file)
{
	file.open("data.csv");
	if (file.is_open() == false)
	{
		std::cerr << "Unable to open data file" << std::endl;
		exit(2);
	}
}

void fill_database(std::map<std::string, float> &database, std::ifstream &file)
{
	std::string line;
	std::string date;
	float		value;

	std::getline(file, line);
	std::getline(file, line);
	while (line.empty() == false)
	{
		date = line.substr(0, 10);
		value = atof(line.substr(11, line.length()).c_str());
		database[date] = value;
		std::getline(file, line);
	}
}

float string_to_float(const std::string &str)
{
	std::stringstream ss(str);
	float value;

	ss >> value;
	return (value);
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


