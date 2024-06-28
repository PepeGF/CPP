# include "BitcoinExchange.hpp"

void    print_exchange(std::string input_file)
{
	std::ifstream	input(input_file.c_str());
	std::string		line;
	
	std::getline(input, line);
	std::getline(input, line);
	while (line.empty() == false)
	{
		check_and_print_input_line(line);
		// checkear fecha
			// año
			// mes
			// dia
		//checkear valor
			// positivo
			// existe
			// no mayor a 1000
		//checkear separador???


		// imprimir
			// buscar fecha en database
				//si fecha no contenida en map, 
					//añadir con valor 0,
					//obtener índice, 
					//restar 1 al índice,
					//eliminar valor recién añadido
					//calcular con value de fecha indice-1
			// fecha => valor input = value map * valor input con precisión
			// Error: tipo error

		//si fecha no contenida en map, añadir con valor 0, obtener índice, restar 1, eliminar valor recién añadido
		std::getline(input, line);
	}
	return ;
}

void check_and_print_input_line(std::string &line)
{
	(void)line;
	validate_date(line);
	validate_separator(line);
	validate_value(line);
	return ;
}

void validate_value(std::string &line)
{
	// float			value;
	std::string aux;

	if (line.length() >= VALUE_INI_INDEX)
	{
		aux = line.substr(VALUE_INI_INDEX);
		if (aux.length() > 4)
		{
			std::cerr << "Error: too large a number.";
			return ;
		}
		//SEGUIR AQUI, CONVETIR A FLOAT COMPROBAR NO MAYOR DE 1000 NI NEGATIVOS
		std::cout << aux << std::endl;
	}
}

void validate_separator(std::string &line)
{
	std::string separator;
	std::string right_separator = " | ";

	separator = line.substr(SEPARATOR_INI_INDEX, SEPARATOR_LEN);
	if (separator != right_separator)
	{
		std::cerr << "Error: wrong separator" << std::endl;
	}
}

void validate_date(std::string &line)
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
		return ;
	}
	for (int i = INDEX_INI; i < YEAR_LEN; i++)
	{
		if (isdigit(date[i]) == false)
		{
			std::cerr << "Error: bad input => " << date << std::endl;
			return;
		}
	}
	year = atoi(line.substr(YEAR_INI_INDEX, YEAR_LEN).c_str());
	for (int i = MONTH_INI_INDEX; i < MONTH_INI_INDEX + MONTH_LEN; i++)
	{
		if (isdigit(date[i]) == false)
		{
			std::cerr << "Error: bad input => " << date << std::endl;
			return;
		}
	}
	month = atoi(line.substr(MONTH_INI_INDEX, MONTH_LEN).c_str());
	if (month > 12)
	{
		std::cout << "Error: bad input => " << date << std::endl;
		return;
	}
	for (int i = DAY_INI_INDEX; i < DAY_INI_INDEX + DAY_LEN; i++)
	{
		if (isdigit(date[i]) == false)
		{
			std::cout << "Error: bad input => " << date << std::endl;
			return;
		}
		// std::cout << date[i];
	}
	day = atoi(line.substr(DAY_INI_INDEX, DAY_LEN).c_str());
	if (day > 31 || day < 1)
	{
		std::cerr << "Error: bad input => " << date << std::endl;
		return;
	}
	if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
	{
		std::cerr << "Error: bad input => " << date << std::endl;
		return;
	}
	if (month == 2 && day > 28)
	{
		std::cerr << "Error: bad input => " << date << std::endl;
		return;
	}
	// std::cout << date << std::endl;
	

	// year = (int)(string_to_float(line.substr(0, 4)));
	

}


void create_database(std::map<std::string, float> &database)
{
	std::ifstream file;
	std::string line;
	open_file(file);
	fill_database(database, file);
	// print_database(database);
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
		value = string_to_float(line.substr(11, line.length()));
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


