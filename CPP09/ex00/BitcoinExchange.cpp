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
