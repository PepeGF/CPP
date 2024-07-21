# pragma once
# include <algorithm>
# include <iostream>

template<typename T>
int easyfind(T& container, int num)
{
	typename T::iterator it = std::find(container.begin(), container.end(), num);
	if (it == container.end())
	{
		std::cout << "No se ha encontrado el valor " << num << " en el contenedor" << std::endl;
		throw std::exception();
	}
	return *it;
}
