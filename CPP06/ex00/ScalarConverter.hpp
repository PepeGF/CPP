#pragma once
# include <iostream>
# include <cstdlib>
# include <sstream>
# include <cmath>

class ScalarConverter
{
private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter& copy);
	ScalarConverter& operator=(const ScalarConverter& rhs);
	static bool check_special(std::string literal);
	static int	get_type(const std::string& literal);
	class Automata
	{
	private:
		void		*data;
		int			alphabet_size;
		std::string	**alphabet = NULL;
		std::string	**errors;
		std::string	str;
		int			state;
		int			ostate;
		int			i;
		int			j;
		int			(Automata::*state_function)(int, int);
		void		automata_init();
		int			get_state(int i, int j);
	public:
		Automata();
		~Automata();
	};
	
	
	
public:
	~ScalarConverter();
	static void convert(const std::string& literal);
};

int ScalarConverter::Automata::get_state(int i, int j)
{
	(void)i;
	(void)j;
	return (0);
}

void	ScalarConverter::Automata::automata_init()
{
	const std::string alphabet_strings[] = {"0123456789", 
											".", 
											"f", 
											"-"}; //añadir aquí las strings necesarias en el futuro
	this->alphabet_size = sizeof(alphabet_strings) / sizeof(std::string *);
	std::cout << "Tamaño del array (4): " << this->alphabet_size << std::endl;
	this->alphabet = new std::string*[alphabet_size];

	const std::string errors_strings[] = {};
	int errors_size = sizeof(errors_strings) / sizeof(std::string *);
	this->errors = new std::string*[errors_size];
	std::cout << "Direccion de errors si no hay nada: " << this->errors << std::endl;

	this->state_function = &ScalarConverter::Automata::get_state;


}

ScalarConverter::Automata::Automata()
{
	automata_init();
}

ScalarConverter::Automata::~Automata()
{
	delete[] this->alphabet;
	delete[] this->errors; //potencial error si no hay nada en el array de errores
}
