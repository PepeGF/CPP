# include "BitcoinExchange.hpp"

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
