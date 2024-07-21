#include "easyfind.hpp"
# include <vector>

int main()
{
	std::vector<int> v;

	for (int i = 0; i < 10; i++)
	{
		v.push_back(i*i*10);
		std::cout << v[i] << " ";
	}
	std::cout << "\n---------------------------------------------" << std::endl;
	try	{
		std::cout << easyfind(v, 0) << std::endl;
	}
	catch(const std::exception& e)	{
		std::cerr << "Value not found" << std::endl;
	}
	try	{
		std::cout << easyfind(v, 360) << std::endl;
	}
	catch(const std::exception& e)	{
		std::cerr << "Value not found" << std::endl;
	}
	try	{
		std::cout << easyfind(v, 360000) << std::endl;
	}
	catch(const std::exception& e)	{
		std::cerr << "Value not found" << std::endl;
	}
	return 0;
}
