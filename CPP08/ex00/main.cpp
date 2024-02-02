#include "easyfind.hpp"

int main()
{
	std::vector<int> v;

	for (int i = 0; i < 10; i++)
	{
		v.push_back(i*i*10);
		std::cout << v[i] << " ";
	}
	std::cout << "\n---------------------------------------------" << std::endl;
	std::cout << easyfind(v, 0)[0] << std::endl;
	std::cout << easyfind(v, 360)[0] << std::endl;
	try
	{
		std::cout << easyfind(v, 360000)[0] << std::endl;
	}
	catch(const std::runtime_error& e){}

	/* std::cout << easyfind(v, 0) << std::endl;
	std::cout << easyfind(v, 360) << std::endl;
	try
	{
		std::cout << easyfind(v, 360000) << std::endl;
	}
	catch(const std::runtime_error& e){} */


	return 0;
}

/* 	std::vector<int>::iterator it = std::find(v.begin(), v.end(), 160);

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
	std::cout << *it << std::endl;
	std::cout << &it << std::endl;
	std::cout << &(*it) << std::endl;
	std::cout << "---------" << std::endl;
	std::cout << v.size() << std::endl;
 */