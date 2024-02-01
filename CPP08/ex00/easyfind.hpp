# include <algorithm>
# include <vector>

template<std::vector<typename T> U, int num>
T& easyfind(U& wololo, int num)
{
	T aux = std::find(wololo.begin(), wololo.end(), num);
	return aux;
}