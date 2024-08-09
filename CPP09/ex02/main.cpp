# include "PmergeMe.hpp"

int ronda = 0;

int main(int argc, char const *argv[])
{
	std::vector<int> numbers;

	if (argc > 1)
	{
		numbers = create_fill_container(argc, argv);
		pmergeme(numbers);
		print_vector(numbers);
	}
	return 0;
}

int calculate_max_index(VectInt jacob, int i, VectInt index, int big_len)
{
	if (jacob[i] == big_len)
		return (big_len - 1);
	else
		return (index[jacob[i]]);
}

int binary_search(int num, VectInt big, int idx_min, int idx_max)
{
	int mid;

	if (idx_min == idx_max)
	{
		if (num < big[idx_min])
			return (idx_min);
		else
			return (idx_min + 1);
	}
	if (idx_min > idx_max)
		return idx_min;
	
	mid = (idx_min + idx_max) / 2;
	if (num > big[mid])
		return binary_search(num, big, mid + 1, idx_max);
	else if (num < big[mid])
		return binary_search(num, big, idx_min, mid - 1);
	else
		return mid;
}

VectInt binary_insertion(VectInt &big, VectInt &small)
{
	VectInt jacob;
	VectInt index;
	VectIntIt it;
	int insert_idx;
	int big_len;
	int idx_jacob;

	big_len = static_cast<int>(big.size());
	jacob = create_serie(static_cast<int>(small.size()) - 1);
	for (size_t i = 0; i < big.size(); i++)
		index.push_back(i);
	for (int i = 0; i < static_cast<int>(small.size()); i++)
	{
		idx_jacob = calculate_max_index(jacob, i, index, big_len);
		insert_idx = binary_search(small[jacob[i]], big, 0, idx_jacob);
		it = big.begin();
		big.insert(it + insert_idx, small[jacob[i]]);
		for (size_t j = 0; j < index.size(); j++)
		{
			if (insert_idx <= index[j])
				index[j]++;
		}
	}
	return big;
}


VectInt pmergeme(VectInt &numbers)
{
	VectInt big;
	VectInt small;
	int		last;

	create_containers(big, small, numbers);
	if (numbers.size() % 2 == 1)
	{
		last = numbers.back();
		small.push_back(last);
	}
	ronda++;
	if (big.size() > 1)
		numbers = pmergeme(big);
	ronda--;
	numbers = binary_insertion(big, small);
	return numbers;
}
























/* 

void print_all_antes(VecPairInt bigger_sort,VecPairInt bigger,VecPairInt bigger_replica,VecPairInt smaller, VecPairInt smaller_replica)
{
	std::cout << "------------ANTES DE LA RECURSIVIDAD-------------\n\n";
	std::cout << "bigger parámetro (bigger_sort):\n";
	print_vector(bigger_sort);
	std::cout << "bigger: \n";
	print_vector(bigger);
	std::cout << "\nbigger_replica: \n";
	print_vector(bigger_replica);
	std::cout << "\nsmaller: \n";
	print_vector(smaller);
	std::cout << "\nsmaller_replica: \n";
	print_vector(smaller_replica);
}

void print_all_despues(VecPairInt bigger_sort,VecPairInt bigger,VecPairInt bigger_replica,VecPairInt smaller, VecPairInt smaller_replica)
{
	std::cout << "······    DESUPUÉS DE LA RECURSIVIDAD     ······\n\n";
	std::cout << "bigger parámetro (bigger_sort):\n";
	print_vector(bigger_sort);
	std::cout << "bigger: \n";
	print_vector(bigger);
	std::cout << "\nbigger_replica: \n";
	print_vector(bigger_replica);
	std::cout << "\nsmaller: \n";
	print_vector(smaller);
	std::cout << "\nsmaller_replica: \n";
	print_vector(smaller_replica);
}

VecPairInt pmergeme(VecPairInt &bigger_sort) // ojo, quizas no sirva referencia
{
	PairInt last;
	VecPairInt bigger;
	VecPairInt bigger_replica;
	VecPairInt smaller;
	VecPairInt smaller_replica;
ronda++;
	
	last = get_last_from_odd(bigger_sort); // soluciona el problema impar
	create_vectors(bigger_sort, bigger, bigger_replica, smaller, smaller_replica);
	add_last_to_smaller(last, smaller, smaller_replica);
	// print_all_antes(bigger_sort, bigger, bigger_replica, smaller, smaller_replica);
	if (bigger.size() != 1)		
		//salida para la recursividad
		bigger_sort = pmergeme(bigger);
ronda--;

	// print_vector(bigger_replica);
// std::cout << "Ronda: " << ronda << std::endl;
	// print_all_despues(bigger_sort, bigger, bigger_replica, smaller, smaller_replica);
	
	//sorting
	bigger_sort = sort_with_insertion(bigger_sort, bigger_replica, smaller, smaller_replica, last);

	return bigger_sort;
}



VecPairInt sort_with_insertion(VecPairInt &bigger_sort, VecPairInt &bigger_replica, VecPairInt &smaller, VecPairInt &smaller_replica, PairInt &last)
{
	(void)bigger_sort, (void)bigger_replica; (void)smaller; (void)smaller_replica; (void)last;

	std::vector<int> jacobsthal_serie;
	std::vector<int> index_aux;
	VectPairIntIter it = bigger_replica.begin();
	int insert_idx;
	int bigger_replica_len;

	bigger_replica_len = static_cast<int>(bigger_replica.size());
	jacobsthal_serie = create_serie(smaller.size() - 1);
	for (int i = 0; i < bigger_replica_len; i++)
		index_aux.push_back(i);
	for (int i = 0; i < static_cast<int>(smaller_replica.size()); i++)
	{
		insert_idx = binary_search(bigger_replica, 
									  smaller_replica[jacobsthal_serie[i]], 
									  0, 
									  jacobsthal_serie[i] == static_cast<int>(bigger_replica.size()) 
										  ? static_cast<int>(bigger_sort.size()) - 1 
										  : index_aux[jacobsthal_serie[i]]);		
		bigger_replica.insert(it + insert_idx, smaller_replica[jacobsthal_serie[i]]);
		for (size_t j = 0; j < index_aux.size(); j++)
		{
			if (insert_idx <= index_aux[j])
				index_aux[j]++;
		}
		// if (last.second != -1)
		// 	insert_idx = binary_insertion(bigger_sort, 
		// 									last, 
		// 									0, 
		// 									static_cast<int>(bigger_sort.size()) - 1);
	}
	// std::cout << "\nBIGGER_SORT:\n";
	// print_vector(bigger_sort);
	return bigger_replica;
}

int min(int one, int sec)
{
	return (one <= sec ? one : sec);
}

int  binary_search(VecPairInt &bigger_sort, PairInt to_insert, int idx_min, int idx_max)
{
	int mid;

	if (bigger_sort.size() == 0)
	{
		// TODO: borrar este print
		std::cout << "WOLOLOOOOOOOOOOOOOOOOOOOOO\n" << std::endl;
		bigger_sort.insert(bigger_sort.begin(), to_insert);
		return (0);
	}
	if (idx_min == idx_max)
	{
		if (to_insert > bigger_sort[idx_min])
		{
			bigger_sort.insert(bigger_sort.begin() + min(idx_max, idx_min) + 1, to_insert);
		if (to_insert < bigger_sort[idx_min])
			return (idx_min);
		else
			return (idx_min + 1);
		}
		else
		{
			bigger_sort.insert(bigger_sort.begin() + min(idx_max, idx_min), to_insert);
			return (idx_min);
		}
	}
	}
	if (idx_min > idx_max)
		return idx_min;
	mid = (idx_max + idx_min) / 2;
	if (to_insert > bigger_sort[mid])
		return binary_search(bigger_sort, to_insert, mid + 1, idx_max);
	else if (to_insert < bigger_sort[mid])
		return binary_search(bigger_sort, to_insert, idx_min, mid - 1);
	else
		return mid;

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
 */
	/* for (size_t t = 0; t < jacobsthal_serie.size(); t++)
		std::cout << jacobsthal_serie[t] << " ";
	std::cout << "\n" << std::endl; */

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
/* 
std::cout << "------------ANTES DE LA RECURSIVIDAD-------------\n\n";
	std::cout << "bigger parámetro (bigger_sort):\n";
	print_vector(bigger_sort);
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
*/