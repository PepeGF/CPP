# include "BitcoinExchange.hpp"

void    print_exchange(std::string input_file, std::map<std::string, float> &database)
{
	std::ifstream	input(input_file.c_str());
	std::string		line;
	std::string		date;
	float			input_value;
	std::map<std::string, float>::iterator it;

	std::getline(input, line); //ignorar primera línea de encabezados
	std::getline(input, line);
	while (line.empty() == false)
	{
		if (check_and_print_input_line(line) == LINE_OK)
		{
			input_value = atof(line.substr(VALUE_INI_INDEX).c_str());
			date = line.substr(INDEX_INI, LEN_DATE_STRING);
			it = database.find(date);
			if (it != database.end()) // fecha en base de datos
				print_output(date, input_value, database[date]);
			else // fecha no en base dataos
			{
				database.insert(std::pair<std::string, float>(date, 0));
				it = database.find(date);
				if (it != database.begin())
				{
					--it;
					print_output(date, input_value, it->second);
					database.erase(++it);
				}
				else
					print_output(date, input_value, it->second);
			}
		}
		std::getline(input, line);
	}
	return ;
}

void print_output(std::string date, float input_value, float database_value)
{
	std::cout << date << " => " 
		<< input_value << " = "
		<< database_value * input_value
		<< std::endl;
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
				return(print_invalid_line("Error: invalid input."));
			if (aux[i] == '.')
			{
				dots_counter++;
				if (dots_counter > 1)
				return(print_invalid_line("Error: invalid input."));
			}
		}
		value = atof(aux.c_str());
		if (value < 0)
			return(print_invalid_line("Error: not a positive number."));
		if (value > 1000)
			return(print_invalid_line("Error: too large a number."));
	}
	return LINE_OK;
}

int validate_separator(std::string &line)
{
	std::string separator;
	std::string right_separator = " | ";

	separator = line.substr(SEPARATOR_INI_INDEX, SEPARATOR_LEN);
	if (separator != right_separator)
		return(print_invalid_line("Error: wrong separator"));
	return LINE_OK;
}

int validate_date(std::string &line)
{
	std::string date;

	date = line.substr(INDEX_INI, LEN_DATE_STRING);

	if (validate_date_format(line) == INVALID_LINE)
		return INVALID_LINE;
	if (validate_month(date, line) == INVALID_LINE)
		return INVALID_LINE;
	if (validate_day(date) == INVALID_LINE)
		return INVALID_LINE;
	if (validate_real_day(line, date) == INVALID_LINE)
		return INVALID_LINE;
	return LINE_OK;
}

int validate_real_day(std::string line, std::string date)
{
	int day;
	int month;

	month = atoi(line.substr(MONTH_INI_INDEX, MONTH_LEN).c_str());
	day = atoi(line.substr(DAY_INI_INDEX, DAY_LEN).c_str());
	if (day > 31 || day < 1)
		return print_invalid_date(date);
	if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
		return print_invalid_date(date);
	if (month == 2 && day > 28)
		return print_invalid_date(date);
	return LINE_OK;
}

int validate_day(std::string date)
{
	for (int i = DAY_INI_INDEX; i < DAY_INI_INDEX + DAY_LEN; i++)
	{
		if (isdigit(date[i]) == false)
			return print_invalid_date(date);
	}
	return LINE_OK;
}

int validate_month(std::string date, std::string line)
{
	int month;

	for (int i = MONTH_INI_INDEX; i < MONTH_INI_INDEX + MONTH_LEN; i++)
	{
		if (isdigit(date[i]) == false)
			return print_invalid_date(date);
	}
	month = atoi(line.substr(MONTH_INI_INDEX, MONTH_LEN).c_str());
	if (month > 12)
		return print_invalid_date(date);
	return LINE_OK;
}

int validate_year(std::string date)
{
	for (int i = INDEX_INI; i < YEAR_LEN; i++)
	{
		if (isdigit(date[i]) == false)
			return print_invalid_date(date);
	}
	return LINE_OK;
}

int validate_date_format(std::string date)
{
	if (date[FIRST_MINUS_INDEX] != '-' || date[SECOND_MINUS_INDEX] != '-')
		return print_invalid_date(date);
	return (LINE_OK);
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


