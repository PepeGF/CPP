#include <iostream>
#include <vector>
#include <algorithm>

int  binary_search(std::vector<int> &v, int num, int idx_min, int idx_max)
{
	int mid;

	if (idx_min == idx_max)
	{
		if (num < v[idx_min])
			return (idx_min);
		else
			return (idx_min + 1);
	}
	if (idx_min > idx_max)
		return idx_min;
	
	mid = (idx_min + idx_max) / 2;
	if (num > v[mid])
		return binary_search(v, num, mid + 1, idx_max);
	else if (num < v[mid])
		return binary_search(v, num, idx_min, mid - 1);
	else
		return mid;
}

int main(int argc, char* argv[]) {
	std::vector<int> v{118, 120, 176, 189, 300, 392, 395, 400, 472, 474, 482, 485, 500, 541, 577, 658, 755, 777, 788, 900, 931};
					//	0	 1	  2	   3	4	 5	  6	   7	8	 9	  10   11	12	 13	  14   15   16   17   18   19   20
	int num = atoi(argv[1]);
	int idx_i = atoi(argv[2]);
	int idx_f = atoi(argv[3]);
	int idx_inserted;
	std::vector<int>::iterator it = v.begin();
	std::cout << "---->>>> " << v.back() << std::endl;
	std::cout << "---->>>>" << std::endl;
	
	idx_inserted = binary_search(v, num, idx_i, idx_f);
	v.insert(it + idx_inserted, num);
	std::cout << "Insertado en: " << idx_inserted << std::endl;
	for (size_t i = 0; i < v.size(); i++)
		std::cout << v[i] << " ";
	std::cout << std::endl;
	
	(void)idx_inserted;
	return 0;
}

/* 
118, 119, 176, 189, 300, 392, 395, 400, 472, 474, 482, 485, 500, 541, 577, 658, 755, 777, 789, 900, 931

 */

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
		std::cout << "Ronda: " << ronda << "Num: " << small[jacob[i]] << std::endl;
		std::cout << "BIG:\n";
		print_vector(big);
		std::cout << "SMALL:\n";
		print_vector(small);
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
	big = binary_insertion(big, small);

	return big;
}

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
