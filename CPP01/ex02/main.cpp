#include <iostream>

int	main()
{
	std::string	string;
	std::string *stringPTR;
	std::string &stringREF = string;

	string = "HI THIS IS BRAIN";
	stringPTR = &string;

	std::cout << std::endl 
			<< "string memory address:    " << &string << std::endl
			<< "stringPTR memory address: " << stringPTR << std::endl
			<< "stringREF memory address: " << &stringREF << std::endl;

	std::cout << std::endl
			<< "string:            " << string << std::endl
			<< "stringPTR content: " << *stringPTR << std::endl
			<< "stringREF content: " << stringREF << std::endl;

	return (0);
}
