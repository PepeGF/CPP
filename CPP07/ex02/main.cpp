# include "Array.hpp"

int main( void )
{
	Array<int> array;
	std::cout << "Dirección array por defecto: " << &array << std::endl;

	Array<int> otro(42);
	std::cout << "Array vacío: \nLongitud array: " << otro.size() 
				<< "\nContenido del Array:\n";
	for (int i = 0; i < 42 - 1; i++)
	{
		std::cout << otro[i] << ", ";
	}
	std::cout << otro[41] << std::endl;
	std::cout << "Asignar valor fuera de rango:\n\t";
	try
	{
		otro[500] = 1903;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "Asignar valor índice negativo:\n\t";
	try
	{
		otro[-500] = 1903;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "Asignar valor válido:\n";
	for (int i = 10; i < 20; i++)
		otro[i] = -2 * i * i;
	for (size_t i = 0; i < otro.size() - 1; i++)
		std::cout << otro[i] << ", ";
	std::cout << otro[41] << std::endl;
	

	return 0;
}