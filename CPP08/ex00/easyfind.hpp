# include <algorithm>
# include <vector>
# include <iostream>

template<typename Container>
typename Container::iterator easyfind(Container& wololo, int num)
{
	typename Container::iterator it = std::find(wololo.begin(), wololo.end(), num);
	if (it == wololo.end())
	{
		std::cout << "No se ha encontrado el valor " << num << " en el contenedor" << std::endl;
		throw std::runtime_error("Value not found");
	}
	return it;
}

// si el subject de correccción no dice lo contrario esta implementación no es la que quiero:

/* template<typename Container>
int easyfind(Container& wololo, int num)
{
	typename Container::iterator it = std::find(wololo.begin(), wololo.end(), num);
	if (it == wololo.end())
	{
		std::cout << "No se ha encontrado el valor " << num << " en el contenedor" << std::endl;
		throw std::runtime_error("Value not found");
	}
	return *it;
} */