# include "PmergeMe.hpp"

void validate_number(char const *argv)
{
	std::string aux = static_cast<std::string>(argv);

	for (size_t i = 0; i < aux.length(); i++)
	{
		if (isdigit(argv[i]) == false)
		{
			std::cerr << "Error" << std::endl;
			exit(EXIT_FAILURE);
		}
	}
	double temp;
	temp = atof(argv);
	if (temp > INT_MAX || temp < INT_MIN)
	{
		std::cerr << "Error" << std::endl;
		exit(EXIT_FAILURE);
	}
}

void print_vector(VecPairInt vect)
{
	for (VectPairIntIter it = vect.begin(); it != vect.end(); it++)
		std::cout << std::setfill(' ') << std::setw(2) << (*it).first << " ";
	std::cout << std::endl;
	for (VectPairIntIter it = vect.begin(); it != vect.end(); it++)
		std::cout <<  "-- ";
	std::cout << std::endl;
	for (VectPairIntIter it = vect.begin(); it != vect.end(); it++)
		std::cout << std::setfill(' ') << std::setw(2) << (*it).second << " ";
	std::cout << std::endl;
} 


void print_pair(PairInt pair)
{
	std::cout << pair.first << " || " << pair.second << std::endl;
}

