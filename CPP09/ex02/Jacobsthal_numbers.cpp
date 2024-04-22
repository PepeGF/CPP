# include <list>
# include <vector>
# include <iostream>
# include <cstdlib>

std::vector<int> jacobsthal(int n)
{
	// esta función genera una lista de los n primeros números de la serie de Jacobsthal
	// Jn = Jn-1 +2*Jn-2

	std::vector<int> aux(0);

	if (n == 0 || n > 33) // si es mayor de 33 de genera int overflow
		return aux;
	aux.push_back(0);
	if (n == 1)
		return aux;
	aux.push_back(1);
	if (n == 2)
		return aux;
	for (int i = 2; i < n; i++)
	{
		aux.push_back(aux[i - 1] + 2 * aux[i - 2]);
	}
	return aux;
}

bool isinvector(int num, std::vector<int> vector)
{
	for (size_t i = 0; i < vector.size(); i++)
	{
		if (num == vector[i])
			return true;
	}
	return false;
}

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
}

int main(int argc, char *argv[])
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
}