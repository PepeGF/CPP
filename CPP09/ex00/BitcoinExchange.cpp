# include "BitcoinExchange.hpp"

void    print_exchange(std::string input_file)
{
	(void)input_file;

	return ;
}

std::map<std::string, double> create_database()
{
	std::map<std::string, double> database;

	std::ifstream file;
	std::string line;
	open_file(file);
	std::getline(file, line);
	while (line.empty() == false)
	{
		database.insert(std::pair<std::string, double>(line.substr(0, 10), std::atof(line.substr(11, line.length()).c_str())));
		std::cout << "Primera parte: " << line.substr(0, 10) << " Segunda parte: " << std::atof(line.substr(11, line.length()).c_str()) << std::endl;
		std::getline(file, line);
	}
	
	return (database);
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
