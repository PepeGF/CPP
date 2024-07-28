# include "PmergeMe.hpp"

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

std::vector<int> create_serie(int n)
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

// # include <list>
// # include <vector>
// # include <iostream>
// # include <cstdlib>

/* 
void print_vector(std::vector<int> vector)
{
	for (size_t i = 0; i < vector.size(); i++)
		std::cout << vector[i] << " ";
	std::cout << std::endl;
} */
/* 
void print_vector(std::vector<int> vector, std::string texto)
{
	std::cout << texto << std::endl;
	for (size_t i = 0; i < vector.size(); i++)
		std::cout << vector[i] << " ";
	std::cout << std::endl;
} */


/* 
bool isinvector(int num, std::vector<int> vector)
{
	for (size_t i = 0; i < vector.size(); i++)
	{
		if (num == vector[i])
			return true;
	}
	return false;
} */
/* 
std::vector<int> insertion(std::vector<int> jacobsthal_numbers)
{
	std::vector<int> aux(0);

	for (size_t i = 1; i < jacobsthal_numbers.size(); i++)
	{
		for (int j = jacobsthal_numbers[i]; j > jacobsthal_numbers[i - 1]; j--)
		{
			aux.push_back(j);
		}
	}
	return aux;
} */

/* int main(int argc, char *argv[])
{
	(void)argc;
	int n;

	n = atoi(argv[1]);
	std::vector<int> jacobsthal_numbers;
	jacobsthal_numbers = jacobsthal(n);
	// esto es solo para comprobar
	for (size_t i = 0; i < jacobsthal_numbers.size(); i++)
	{
		std::cout << jacobsthal_numbers[i] << ", ";
	}
	std::cout << std::endl;

	//lista de inserción:
	std::vector<int> insert;
	insert = insertion(jacobsthal_numbers);
	// esto es solo para comprobar
	for (size_t i = 0; i < insert.size(); i++)
	{
		std::cout << insert[i] << ", ";
	}
	std::cout << std::endl;

	return 0;
} */
/* 
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
} */
/* 
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
} */
/* 
int main()
{
	std::vector<int> wololo;
	std::vector<int> serie;
	int n = 65;
	wololo = jacobsthal(n);
	serie = create_serie(wololo, n);
	print_vector(wololo);
	print_vector(serie);
	return 0;
} */
