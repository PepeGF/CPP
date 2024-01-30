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

	return 0;
}