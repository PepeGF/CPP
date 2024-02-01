# include <algorithm>

template<typename T, int num>
T& easyfind(T& wololo, int num)
{
	T aux = std::find(wololo.begin(), wololo.end(), num);
	return aux;
}