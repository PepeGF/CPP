# include "iter.hpp"



int main( void ) 
{
	int array[] = {42, -42, 0, INT_MAX, INT_MIN};
	int len = sizeof(array) / sizeof(int);
	iter(array, len, print);

	std::string array_char[] = {"Hola", "mundo", "Forza Atleti"};
	len = sizeof(array_char) / sizeof(std::string);
	iter(array_char, len, print);
	return 0;
}

	/* int tab[] = {0, 1, 2, 3, 4};
	Awesome tab2[5];
	len = sizeof(tab2)/sizeof(Awesome);
	iter(tab, 5, print);
	iter(tab2, len, print); */