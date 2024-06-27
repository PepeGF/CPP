# include "BitcoinExchange.hpp"

int main(int argc, char const *argv[])
{
	if (argc != 2)
	{
		std::cerr << "Error, not enought arguments\n" 
				<< "Usage: ./btc input.txt" << std::endl;
		return (EXIT_FAILURE);
	}
	else
	{
		std::map<std::string, double> database;

		database = create_database();
		print_exchange(argv[1]);
	}
	return (EXIT_SUCCESS);
}
