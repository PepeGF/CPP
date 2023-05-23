#include "Harl.hpp"

int main()
{
	Harl harl;
	std::string aux[5] = 
	{
		"debug",
		"info",
		"warning",
		"error",
		"wololo"
	};

	for (int i = 0; i <= 4; i++)
	{
		std::cout << aux[i] << ":" << std::endl;
		harl.complain(aux[i]);
		std::cout << std::endl;
	}
	return (0);
}

// int	main()
// {
// 	Harl harl;
// 	std::string aux;

// 	aux = "debug";
// 	std::cout << aux << ":" << std::endl;
// 	harl.complain(aux);
// 	std::cout << std::endl;
// 	aux = "info";
// 	std::cout << aux << ":" << std::endl;
// 	harl.complain(aux);
// 	std::cout << std::endl;
// 	aux = "warning";
// 	std::cout << aux << ":" << std::endl;
// 	harl.complain(aux);
// 	std::cout << std::endl;
// 	aux = "error";
// 	std::cout << aux << ":" << std::endl;
// 	harl.complain(aux);
// 	std::cout << std::endl;
// 	aux = "wololo";
// 	std::cout << aux << ":" << std::endl;
// 	harl.complain(aux);
// 	return (0);
// }