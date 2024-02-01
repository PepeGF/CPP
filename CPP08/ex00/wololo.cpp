# include <vector>
# include <iostream>

int main()
{
	std::vector<int> wololo = {1, 2, 3, 4, 5};

	for (int &x : wololo)
	{
		x++;
		std::cout << x << std::endl;
	}

	std::cout << "------" << std::endl;

	for (std::vector<int>::iterator it = wololo.begin(); it != wololo.end(); ++it)
		std::cout << *it << std::endl;

	std::cout << "------" << std::endl;

	for (int i; i < static_cast<int>(wololo.size()); i++)
		std::cout << wololo[i] << std::endl;

	std::cout << "------" << std::endl;
	return (0);
}