#include <iostream>
#include <fstream>

int	main(int argc, char *argv[])
{
	std::ifstream	infile(argv[1]);
	std::string		buffer;
	std::size_t		found;
	if (argc != 4)
	{
		std::cout 
			<< "Error: wrong number of arguments"
			<< std::endl
			<< "Usage ./my_sed infile reemplaced_string substitute_string"
			<< std::endl;
		return (1);
	}
{
	//probablemente sea lo mismo que verificar !infile
	// if (infile.good() == false)
	// {
	// 	std::cout << "Error: unable to open " << argv[1] << std::endl;
	// }
	}
	if(!infile)
	{
		std::cout << "Error: " << argv[1] << " not found" << std::endl;
		exit (2);
	}
	while (std::getline(infile, buffer))
	{
		found = buffer.find((std::string)argv[2]);
		if (found != std::string::npos)
		{
			std::cout << "text founded in psition " << found << std::endl;
		}
		std::cout << buffer << std::endl;
	}
}
