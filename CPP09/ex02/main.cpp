# include "PmergeMe.hpp"
int pasos = 0;

int main(int argc, char const *argv[])
{
	VecPairInt original;

	if (argc > 1)
	{
		original = create_fill_container(argc, argv);
		pmergeme(original);
	}
	return 0;
}

VecPairInt pmergeme(VecPairInt &original) // ojo, quizas no sirva referencia
{
	PairInt last;
	VecPairInt bigger;
	VecPairInt bigger_replica;
	VecPairInt smaller;
	VecPairInt smaller_replica;;
	
	last = make_even(original); // soluciona el problema del último impar y 
	// facilita la creación de los vectores grande y peq al poder avanzar de 2 en 2
	create_vectors(original, bigger, bigger_replica, smaller, smaller_replica);
	add_last_to_smaller(last, smaller, smaller_replica);
	std::cout << "Paso: " << pasos++ << std::endl;
	print_vector(original);
	original = recursivity(original, bigger);
	std::cout << "->Paso: " << pasos++ << "<-" << std::endl;
	print_vector(original);
	return bigger_replica;
}

VecPairInt recursivity(VecPairInt &original, VecPairInt &bigger)
{
	if (bigger.size() != 1)
		original = pmergeme(bigger);
	return original;
}


void add_last_to_smaller(PairInt &last, VecPairInt &smaller, VecPairInt &smaller_replica)
{
	if (last.second != -1)
	{
		smaller.push_back(std::make_pair(last.first, smaller.size()));
		smaller_replica.push_back(last);
	}
}

void create_vectors(VecPairInt &original,
					VecPairInt &bigger,
					VecPairInt &bigger_replica,
					VecPairInt &smaller,
					VecPairInt &smaller_replica)
{
	int j = 0;

	for (size_t i = 0; i < original.size(); i++)
	{
		if (original[i] > original[i + 1])
		{
			bigger.push_back(std::make_pair(original[i].first, j));
			bigger_replica.push_back(original[i]);
			smaller.push_back(std::make_pair(original[i + 1].first, j));
			smaller_replica.push_back(original[i + 1]);
		}
		else
		{
			smaller.push_back(std::make_pair(original[i].first, j));
			smaller_replica.push_back(original[i]);
			bigger.push_back(std::make_pair(original[i + 1].first, j));
			bigger_replica.push_back(original[i + 1]);
		}
		if (i != original.size() - 1)
			i++;
		j++;
	}
}


PairInt make_even(VecPairInt &original)
{
	PairInt last (-1, -1);
	if (original.size() % 2 == 1)
	{
		last = original.back();
		original.pop_back();
	}
	return last;
}


void wololo(VecPairInt &bigs)
{
	VecPairInt aux = bigs;
	VecPairInt big;
	VecPairInt small;

	for (size_t i = 0; i < bigs.size(); i++)
	{
		if (i == bigs.size() - 1)
			std::cout << "--->>> " << bigs[i + 1].first << std::endl;
		if (bigs[i] > bigs[i + 1])
		{
			big.push_back(bigs[i]);
			small.push_back(bigs[i + 1]);
		}
		else
		{
			big.push_back(bigs[i]);
			small.push_back(bigs[i + 1]);
		}
		if (i != bigs.size() - 1)
			i++;
	}
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
	for (VectPairIntIter it = vect.begin(); 
			it != vect.end(); 
			it++)
	{
		std::cout << (*it).first << " || " << (*it).second << "\n";
	}
	std::cout << std::endl;
}

void print_pair(PairInt pair)
{
	std::cout << pair.first << " || " << pair.second << std::endl;
}

