#include <iostream>
#include <fstream>
#include <cstdlib>

void	input_error(int argc, char *argv[]);
void	infile_error(char **argv);
void	outfile_error(std::string buffer);

int	main(int argc, char *argv[])
{
	std::ifstream	infile(argv[1]);
	std::string		buffer;
	std::string		aux;
	std::size_t		found;
	std::size_t		aux_index;

	input_error(argc, argv);	
	if(!infile)
		infile_error(argv);
	buffer = argv[1];
	buffer = buffer.append(".replace");
	const char *buf = buffer.c_str();
	std::ofstream	outfile(buf);
	if (!outfile)
		outfile_error(buffer);
	while (std::getline(infile, buffer))
	{
		found = 0;
		aux_index = 0;
		aux = "";
		while (true)
		{
			found = buffer.find((std::string)argv[2], aux_index);
			if (found == std::string::npos)
				break;
			aux.append(buffer, aux_index, found - aux_index);
			aux.append(std::string(argv[3]));
			aux_index = found + std::string(argv[2]).length();
		}
		aux.append(buffer, aux_index);
		outfile << aux << std::endl;
	}
	infile.close();
	outfile.close();
}

void	input_error(int argc, char *argv[])
{
	if (argc != 4)
	{
		std::cout 
			<< "Error: wrong number of arguments"
			<< std::endl
			<< "Usage ./replace infile reemplaced_string substitute_string"
			<< std::endl;
		std::exit (1);
	}
	if (((std::string)argv[2]).length() == 0 || ((std::string)argv[3]).length() == 0)
	{
		std::cout << "Error: argument can't be empty" << std::endl;
		std::exit(4);
	}
}

void	infile_error(char **argv)
{
	std::cout << "Error: " << argv[1] << " not found" << std::endl;
	std::exit(2);
}

void	outfile_error(std::string buffer)
{
	std::cout << "Error: unable to create " << buffer << std::endl;
	std::exit(3);	
}