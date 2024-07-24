# include "PmergeMe.hpp"

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
	
	last = get_last_from_odd(bigger_sort); // soluciona el problema del último impar y 
	// facilita la creación de los vectores grande y peq al poder avanzar de 2 en 2
	create_vectors(bigger_sort, bigger, bigger_replica, smaller, smaller_replica);
	add_last_to_smaller(last, smaller, smaller_replica);
	std::cout << "------------ANTES DE LA RECURSIVIDAD-------------\n\n";
	std::cout << "bigger: \n";
	print_vector(bigger);
	std::cout << "\nbigger_replica: \n";
	print_vector(bigger_replica);
	std::cout << "\nsmaller: \n";
	print_vector(smaller);
	std::cout << "\nsmaller_replica: \n";
	print_vector(smaller_replica);
	if (bigger.size() != 1)			//salida para la recursividad
		bigger_sort = pmergeme(bigger);
	std::cout << "······    DESUPUÉS DE LA RECURSIVIDAD     ······\n\n";
	std::cout << "bigger: \n";
	print_vector(bigger);
	std::cout << "\nbigger_replica: \n";
	print_vector(bigger_replica);
	std::cout << "\nsmaller: \n";
	print_vector(smaller);
	std::cout << "\nsmaller_replica: \n";
	print_vector(smaller_replica);
	// std::cout << "smaller_sorted: \n";
	// print_vector(smaller_sorted);

	// sort_len_1(bigger_replica, smaller_replica, last);
	// sort_with_ insertion(bigger_sort, bigger_replica, smaller, smaller_replica, smaller_sorted, last);
	return bigger_replica;
}

VecPairInt sort_with_insertion(VecPairInt &bigger_sort, VecPairInt &bigger_replica, VecPairInt &smaller, VecPairInt &smaller_replica, VecPairInt &smaller_sort, PairInt &last)
{
	(void)bigger_sort;
	(void)bigger_replica;
	(void)smaller;
	(void)smaller_replica;
	(void)smaller_sort;
	(void)last;
/* 	if (smaller_replica.empty() == false)
	{
		replicate_changes(bigger_sort, bigger_replica, smaller, smaller_replica, smaller_sort, last);
		bigger_sort = insert_small_into_big(bigger_sort, smaller_sort);
		
	} */
	return bigger_sort;
}

std::vector<int> jacobsthal(int const n)
{
	// esta función genera una lista de los n primeros números de la serie de Jacobsthal
	// Jn = Jn-1 +2*Jn-2

	int arr[] = {0, 1, 1};
	std::vector<int> aux(arr, arr + sizeof(arr) / sizeof(arr[0]));
	std::vector<int> jacob(arr, arr + sizeof(arr) / sizeof(arr[0]) - 1);
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

std::vector<int> create_serie(std::vector<int> v, int n)
{
	int j = 0;
	std::vector<int> serie;

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

void  binary_insertion(VecPairInt &bigger_sort, PairInt x, int idx_max, int idx_min)
{
	int mid = (idx_max + idx_min) / 2;

	if (bigger_sort.size() == 0)
	{
		bigger_sort.insert(bigger_sort.begin(), x);
		return;
	}
	if (idx_max <= idx_min)
	{
		if (x > bigger_sort[idx_min])
			bigger_sort.insert(bigger_sort.begin() + idx_min + 1, x);
		else
			bigger_sort.insert(bigger_sort.begin() + idx_min, x);
		return;
	}
	if (x > bigger_sort[mid])
		binary_insertion(bigger_sort, x, idx_max, mid + 1);
	else
		binary_insertion(bigger_sort, x, mid - 1, idx_min);
}


void replicate_changes(VecPairInt &bigger_sort, VecPairInt &bigger_replica, VecPairInt &smaller, VecPairInt &smaller_replica, VecPairInt &smaller_sort, PairInt &last)
{
	for (size_t i = 0; i < bigger_sort.size(); i++)
	{
		smaller_sort.push_back(smaller_replica[bigger_sort[i].second]);
		bigger_sort[i].second = bigger_replica[bigger_sort[i].second].second;
	}
	if (bigger_sort.size() == 2)
	{
		bigger_replica = bigger_sort;
		smaller_replica = smaller_sort;
	}
	if (last.second != -1)
	{
		smaller_replica.push_back(last);
		smaller_sort.push_back(last);
		smaller.push_back(std::make_pair(last.first, smaller.size()));
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


PairInt get_last_from_odd(VecPairInt &bigger_sort)
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

/* void binary_insertion(PairInt pair, VecPairInt &bigger_sort, int index_min, int index_max)
{
	int middle;

	if (index_min > index_max)
	{
		bigger_sort.insert(bigger_sort.begin() + index_min, pair);
		return;
	}
	middle = (index_min + index_max) / 2;
	if (pair.first > bigger_sort[middle].first)
		binary_insertion(pair, bigger_sort, middle + 1, index_max);
	else
		binary_insertion(pair, bigger_sort, index_max, middle - 1);
} */
}

/* VecPairInt insert_small_into_big(VecPairInt bigger_sort, VecPairInt smaller_sort)
{
	VecPairInt aux;
	std::vector<size_t> positions;

	aux = bigger_sort;
	for (size_t i = 0; i < aux.size(); i++)
		positions.push_back(i);
	bigger_sort.insert(bigger_sort.begin(), smaller_sort.front());
	for (size_t i = 0; i < positions.size(); i++)
		positions[i]++;
	for (size_t i = 0; i < smaller_sort.size(); i++)
	{
		
	}
} */

/* 
void	sort_len_1(VecPairInt &bigger_replica, VecPairInt &smaller_replica, PairInt& last)
{
	if (bigger_replica.size() == 1)
	{
		bigger_replica.insert(bigger_replica.begin(), smaller_replica[0]);
		insert_last_into_bigger(bigger_replica, smaller_replica, last);
		smaller_replica.clear();   // aclarar para la explicación en la corrección
	}
} */
