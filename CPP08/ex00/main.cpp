// #include "easyfind.hpp"
# include <iostream>
# include <vector>
# include <algorithm>
# include "Wololo.hpp"

int main()
{




	std::vector<int> v;

	// v.push_back(42);

	for (int i = 0; i < 10; i++)
		v.push_back(i*i*10);
	// std::vector<int>::iterator it = std::find(v.begin(), v.end(), 160);

	std::cout << "---------" << std::endl;

	for (size_t i = 0; i < v.size(); i++)
		std::cout << &v[i] << std::endl;

	std::cout << "---------" << std::endl;

	for (std::vector<int>::const_iterator it = v.cbegin(); it != v.cend(); it++)
	{
		std::cout << "-> " << *it << std::endl;
	}
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
/* 
	Wololo uno(2, "hola");
	Wololo otro(uno);

	uno.print();
	std::cout << "-------------------" << std::endl;
	otro.print();
	std::cout << std::endl << "-x-x-x-x-x-x-x-x-x-" << std::endl << std::endl;

	uno.patata[2] = 424242;
	uno.print();
	std::cout << "-------------------" << std::endl;
	otro.print();

	return 0; */

}