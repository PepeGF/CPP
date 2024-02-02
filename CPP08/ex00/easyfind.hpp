# include <algorithm>
# include <vector>

template<typename Container, int num>
Container& easyfind(Container& wololo, int num)
{
	T aux = std::find(wololo.begin(), wololo.end(), num);
	return aux;
}