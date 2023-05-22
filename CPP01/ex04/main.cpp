#include <iostream>
#include <fstream>

int	main(int argc, char *argv[])
{
	std::ifstream	infile(argv[1]);
	std::string		buffer;
	std::string		aux;
	std::size_t		found;
	std::size_t		aux_index;
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
		exit(2);
	}
	buffer = argv[1];
	buffer = buffer.append(".replace");
	std::ofstream	outfile(buffer);
	if (!outfile)
	{
		std::cout << "Error: unable to create " << buffer << std::endl;
		exit(3);
	}
	while (std::getline(infile, buffer))
	{
		found = 0;
		aux_index = 0;
		std::cout << buffer << std::endl;
		while (true)
		{
			found = buffer.find((std::string)argv[2], aux_index);
			//std::cout << "text founded in psition " << found << std::endl;
			if (found == std::string::npos)
				break;
			aux.append(buffer, aux_index, found - aux_index);
			aux.append(std::string(argv[3]));
			aux_index++;
		}
		//outfile.append(buffer, aux_index);
		//outfile << aux << std::endl;
	}
	outfile.close();
}
