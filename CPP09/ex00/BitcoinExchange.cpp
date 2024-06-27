# include "BitcoinExchange.hpp"

void    print_exchange(std::string input_file)
{
	std::ifstream	input;
	std::string		line;
	
	std::getline(input, line);
	std::getline(input, line);
	while (line.empty() == false)
	{
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

void create_database(std::map<std::string, float> &database)
{
	std::ifstream file;
	std::string line;
	open_file(file);
	fill_database(database, file);
	print_database(database);
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


