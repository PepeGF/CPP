# include "PmergeMe.hpp"

VectInt jacobsthal(int const n)
{
	int arr[] = {0, 1, 1};
	VectInt aux(arr, arr + sizeof(arr) / sizeof(arr[0]));
	VectInt jacob(arr, arr + sizeof(arr) / sizeof(arr[0]) - 1);
	int i = aux.size();
	int value;
	while (n > aux.back())
	{
		value = aux[i - 1] + 2 * aux[i - 2];
		aux.push_back(value);
		jacob.push_back(value);
		i++;
	}
	if (n == 0)
	{
		jacob.pop_back();
		return jacob;
	}
	return jacob;
}

VectInt create_serie(int n)
{
	int j = 0;
	std::vector<int> serie;
	std::vector<int> v;

	v = jacobsthal(n);
	if (n == 0 || n == 1)
	{
		return v;
	}
	serie.push_back(0);
	for (size_t i = 1; i < v.size(); i++)
	{
		j = v[i];
		while (j > v[i - 1])
		{
			if (j <= n)
				serie.push_back(j);
			j--;
		}
	}

	return serie;
}


VectInt create_fill_container(int argc, char const *argv[])
{
	VectInt numbers;
	int temp;
	// long int aux;
	
	for (int i = 1; i < argc; i++)
	{
		validate_number(argv[i]);
		temp = atoi(argv[i]);
		numbers.push_back(temp);
	}
	return numbers;
}

void	create_containers(VectInt &big, VectInt &small, VectInt &numbers)
{
	for (size_t i = 0; i < numbers.size() - 1; i++)
	{
		if (numbers[i] > numbers[i + 1])
		{
			big.push_back(numbers[i]);
			small.push_back(numbers[i + 1]);
		}
		else
		{
			small.push_back(numbers[i]);
			big.push_back(numbers[i + 1]);
		}
		if (i != numbers.size() - 1)
			i++;
	}
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

void print_vector(VectInt numbers)
{
	for (size_t i = 0; i < numbers.size(); i++)
	{
		std::cout << numbers[i] << " ";
	}
	std::cout << std::endl;
}



/* void validate_number(char const *argv)
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
 */
