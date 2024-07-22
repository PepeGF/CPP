# include "PmergeMe.hpp"
int pasos = 0;

int main(int argc, char const *argv[])
{
	VecPairInt bigger_sort;

	if (argc > 1)
	{
		bigger_sort = create_fill_container(argc, argv);
		print_vector(bigger_sort);
		pmergeme(bigger_sort);
	}
	return 0;
}

VecPairInt pmergeme(VecPairInt &bigger_sort) // ojo, quizas no sirva referencia
{
	PairInt last;
	VecPairInt bigger;
	VecPairInt bigger_replica;
	VecPairInt smaller;
	VecPairInt smaller_replica;
	VecPairInt smaller_sorted; 		(void)smaller_sorted;
	
	last = make_even(bigger_sort); // soluciona el problema del último impar y 
	// facilita la creación de los vectores grande y peq al poder avanzar de 2 en 2
	create_vectors(bigger_sort, bigger, bigger_replica, smaller, smaller_replica);
	add_last_to_smaller(last, smaller, smaller_replica);
	// std::cout << "Paso: " << pasos++ << std::endl;
	// print_vector(bigger_sort);
	if (bigger.size() != 1)			//salida para la recursividad
		bigger_sort = pmergeme(bigger);
	// bigger_sort = recursivity(bigger_sort, bigger);
	sort_len_1(bigger_replica, smaller_replica, last);
	replicate_changes(bigger_sort, bigger, bigger_replica, smaller, smaller_replica, last);
	// std::cout << "->Paso: " << pasos++ << "<-" << std::endl;
	// print_vector(bigger_sort);
	return bigger_replica;
}

void replicate_changes(VecPairInt &bigger_sort, VecPairInt &bigger_replica, VecPairInt &smaller, VecPairInt &smaller_replica, VecPairInt &smaller_sort, PairInt &last)
{
	(void)bigger_sort;
	(void)bigger_replica;
	(void)smaller;
	(void)smaller_replica;
	(void)smaller_sort;
	(void)last;
}

void	sort_len_1(VecPairInt &bigger_replica, VecPairInt &smaller_replica, PairInt& last)
{
	if (bigger_replica.size() == 1)
	{
		bigger_replica.insert(bigger_replica.begin(), smaller_replica[0]);
		insert_last_into_bigger(bigger_replica, smaller_replica, last);
		smaller_replica.clear();   // aclarar para la explicación en la corrección
	}
}

void insert_last_into_bigger(VecPairInt &bigger_replica, VecPairInt &smaller_replica, PairInt& last)
{
	if (last.second != -1)
	{
		if (bigger_replica[1].first < smaller_replica.back().first)
			bigger_replica.push_back(smaller_replica.back());
		else if (bigger_replica[0].first > smaller_replica.back().first)
			bigger_replica.insert(bigger_replica.begin(), smaller_replica.back());
		else
			bigger_replica.insert(bigger_replica.begin() + 1, smaller_replica.back());
	}
}

VecPairInt recursivity(VecPairInt &bigger_sort, VecPairInt &bigger)
{
	if (bigger.size() != 1)
		bigger_sort = pmergeme(bigger);
	return bigger_sort;
}


void add_last_to_smaller(PairInt &last, VecPairInt &smaller, VecPairInt &smaller_replica)
{
	if (last.second != -1)
	{
		smaller.push_back(std::make_pair(last.first, smaller.size()));
		smaller_replica.push_back(last);
	}
}

void create_vectors(VecPairInt &bigger_sort,
					VecPairInt &bigger,
					VecPairInt &bigger_replica,
					VecPairInt &smaller,
					VecPairInt &smaller_replica)
{
	int j = 0;
	for (size_t i = 0; i < bigger_sort.size(); i++)
	{
		if (bigger_sort[i] > bigger_sort[i + 1])
		{
			bigger.push_back(std::make_pair(bigger_sort[i].first, j));
			bigger_replica.push_back(bigger_sort[i]);
			smaller.push_back(std::make_pair(bigger_sort[i + 1].first, j));
			smaller_replica.push_back(bigger_sort[i + 1]);
		}
		else
		{
			smaller.push_back(std::make_pair(bigger_sort[i].first, j));
			smaller_replica.push_back(bigger_sort[i]);
			bigger.push_back(std::make_pair(bigger_sort[i + 1].first, j));
			bigger_replica.push_back(bigger_sort[i + 1]);
		}
		if (i != bigger_sort.size() - 1)
			i++;
		j++;
	}
}


PairInt make_even(VecPairInt &bigger_sort)
{
	PairInt last (-1, -1);
	if (bigger_sort.size() % 2 == 1)
	{
		last = bigger_sort.back();
		bigger_sort.pop_back();
	}
	return last;
}


VecPairInt create_fill_container(int argc, char const *argv[])
{
	VecPairInt bigger_sort;
	PairInt temp;
	// long int aux;
	
	for (int i = 1; i < argc; i++)
	{
		validate_number(argv[i]);
		temp.first = atoi(argv[i]);
		temp.second = i - 1;
		bigger_sort.push_back(temp);
	}
	return bigger_sort;
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
	for (VectPairIntIter it = vect.begin(); it != vect.end(); it++)
		std::cout << std::setfill(' ') << std::setw(3) << (*it).first << " ";
	std::cout << std::endl;
	for (VectPairIntIter it = vect.begin(); it != vect.end(); it++)
		std::cout <<  "--- ";
	std::cout << std::endl;
	for (VectPairIntIter it = vect.begin(); it != vect.end(); it++)
		std::cout << std::setfill(' ') << std::setw(3) << (*it).second << " ";
	std::cout << std::endl;
}


void print_pair(PairInt pair)
{
	std::cout << pair.first << " || " << pair.second << std::endl;
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