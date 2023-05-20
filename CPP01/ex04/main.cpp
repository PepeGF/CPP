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
		found = 0;
		std::cout << buffer << std::endl;
		while (true)
		{
			found = buffer.find((std::string)argv[2], found);
			std::cout << "text founded in psition " << found << std::endl;
			if (found == std::string::npos)
				break;
			found++;
		}
	}
}
