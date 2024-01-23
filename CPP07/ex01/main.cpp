# include "iter.hpp"



int main( void ) 
{
	int array[] = {42, -42, 0, INT_MAX, INT_MIN};
	size_t len = sizeof(array) / sizeof(int);
	iter(array, len, print);

	std::string array_char[] = {"Hola", "mundo", "Forza Atleti"};
	len = sizeof(array_char) / sizeof(int);
	iter(array_char, len, print);

	return 0;
}