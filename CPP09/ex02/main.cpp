# include "PmergeMe.hpp"

int main(int argc, char const *argv[])
{
	if (argc > 1)
	{
		pmergeme(argc, argv);
	}
	return 0;
}

void pmergeme(int argc, char const *argv[])
{
	std::vector< std::pair<int, int> > original;
	std::pair<int, int> temp;
	// long int aux;
	
	for (int i = 1; i < argc; i++)
	{
		validate_number(argv[i]);
		temp.first = atoi(argv[i]);
		temp.second = i;                //i - 1???
		
		original.push_back(temp);
		// aux = argv[i]
		// std::cout << argv[i] << std::endl;
	}
	print_vector(original);
	std::cout << "De momento vale" << std::endl;
}

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

void print_vector(std::vector< std::pair<int, int> > vect)
{
	// std::vector<std::pair<int, int> >::iterator it;
	for (std::vector< std::pair<int, int> >::iterator it = vect.begin(); 
			it != vect.end(); 
			it++)
	{
		std::cout << (*it).first << " || " << (*it).second << "\n";
	}

	// for (size_t i = 0; i < vect.size(); i++)
	// {
	// 	std::cout << vect[i].first << " || " << vect[i].second << "\n"; 
	// }
	std::cout << std::endl;
}

