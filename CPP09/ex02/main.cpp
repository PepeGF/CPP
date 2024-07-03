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
	VecPairInt original;
	
	original = create_fill_container(argc, argv);

	wololo(original);

}

void wololo(VecPairInt &bigs)
{
	VecPairInt aux = bigs;
	VecPairInt big;
	VecPairInt small;

	std::cout << &aux << " || " << &bigs << std::endl;
}

VecPairInt create_fill_container(int argc, char const *argv[])
{
	VecPairInt original;
	PairInt temp;
	// long int aux;
	
	for (int i = 1; i < argc; i++)
	{
		validate_number(argv[i]);
		temp.first = atoi(argv[i]);
		temp.second = i;                //i - 1???
		original.push_back(temp);
	}
	return original;
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

void print_vector(VecPairInt vect)
{
	// std::vector<PairInt >::iterator it;
	for (VectPairIntIter it = vect.begin(); 
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

