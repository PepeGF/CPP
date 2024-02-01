// #include "easyfind.hpp"
# include <iostream>
# include <vector>
# include <algorithm>

int main()
{
	std::vector<int> v;

	// v.push_back(42);

	for (int i = 0; i < 2; i++)
		v.push_back(i*i*10);
	// std::vector<int>::iterator it = std::find(v.begin(), v.end(), 160);

	std::cout << "---------" << std::endl;

	for (size_t i = 0; i < v.size(); i++)
		std::cout << &v[i] << std::endl;

	std::cout << "---------" << std::endl;

	for (int &x : v)
	{
		std::cout << x << std::endl;
	}
	std::cout << "---------" << std::endl;
	// std::cout << *it << std::endl;
	// std::cout << &it << std::endl;
	// std::cout << &(*it) << std::endl;
	std::cout << "---------" << std::endl;
	std::cout << v.size() << std::endl;
	return 0;
}