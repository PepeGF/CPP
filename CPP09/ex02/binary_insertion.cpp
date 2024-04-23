# include <iostream>
# include <vector>
# include <cstdlib>


std::vector<int>  binary_insertion(std::vector<int> vect, int x)
{
	std::vector<int> aux = vect;
	int i = 0;
	int j = aux.size() - 1;

	if (x < aux[0])
	{
		aux.insert(aux.begin(), x);
	}
	else if (x > aux[aux.size() - 1])
	{
		aux.push_back(x);
	}
	else
	{
		while (i + 1 != j)
		{
			if (x < aux[(i + j) / 2])
			{
				j = (i + j) / 2;
			}
			else if (x > aux[(i + j) / 2])
			{
				i = (i + j) / 2;
			}
			else
				std::exit(1);
		}
		aux.insert(aux.begin() + j, x);
	}
	return aux;
}

int main()
{
	//cambiar estos 2 valores para cambiar las listas generadas:
	int long_lista = 9;
	int num_delete = 4;
	std::vector<int> vect;

	// darle valores al vector
	for (int i = 0; i < long_lista; i++)
	{
		vect.push_back(i + 1);
	}
	// 1, 2, 3, 4, 5, 6, 7, 8, 9
	//eliminar el elemento de índice...
	vect.erase(vect.begin() + num_delete - 1); 

	//numero a insertar en la lista ordenada, el mismo que se ha borrado
	int x = num_delete; 
	// 1, 2, 3, -4-, 5, 6, 7, 8, 9

	std::cout << "Antes:" << std::endl;
	for (size_t i = 0; i < vect.size(); i++)
		std::cout << vect[i] << ", ";
	std::cout << std::endl;


	std::vector<int> vect_nuevo = binary_insertion(vect, x);
	
	
	std::cout << "Después:" << std::endl;
	for (size_t i = 0; i < vect_nuevo.size(); i++)
	{
		std::cout << vect_nuevo[i] << ", ";
	}
	std::cout << std::endl;
	
	return (0);
}