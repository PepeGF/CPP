# include "Automata.hpp"

int Automata::set_state(int i, int j)
{
	int state[][6] = {
	//   #   .   f   -   ^
		{2,  3,  3,  1,  3}, // initial state	0
		{2,  6,  6,  6,  6}, // minus found		1
	    {2,  4,  5,  6,  6}, // int				2 -> overflow
		{6,  6,  6,  6,  6}, // char			3
		{4,  6,  5,  6,  6}, // double			4
		{6,  6,  6,  6,  6}, // float			5
		{6,  6,  6,  6,  6}  // string			6
	};
	return (state[i][j]);
}

void	Automata::automata_init()
{
	std::string alphabet_strings[] = {"0123456789", 
									  ".", 
									  "f", 
									  "-"
									  };	//añadir aquí las strings necesarias en el futuro

	// init alphabet								
	this->alphabet_size = sizeof(alphabet_strings) / sizeof(std::string);
	this->alphabet = new std::string[alphabet_size];
	for (int i = 0; i < alphabet_size; i++)
	{
		this->alphabet[i] = alphabet_strings[i];
	}

	//init errors
	const std::string errors_strings[] = {};
	int errors_size = sizeof(errors_strings) / sizeof(std::string);
	this->errors = new std::string[errors_size];
	for (int i = 0; i < errors_size; i++)
	{
		this->errors[i] = errors_strings[i];
	}

	//evaluate
	this->state_function = &Automata::set_state;
}

Automata::Automata(void *data) : data(data), state(0)
{
	automata_init();
}

Automata::Automata() : state(0)
{
	automata_init();
}

Automata::~Automata()
{
	delete[] this->alphabet;
	// delete this->alphabet;
	delete[] this->errors; //potencial error si no hay nada en el array de errores
	
}

int	Automata::get_state()
{
	return (evaluate());
}

int Automata::evaluate()
{
	int len;

	this->ostate = 0;
	this->i = 0;
	len = this->str.length();
	while (this->i < len)
	{
		this->state = this->set_state(this->state, idx(this->alphabet, this->str[this->i]));
		++(this->i);
	}
	return (this->state); //no lo tengo del todo claro...
}

int Automata::idx(std::string *alphabet, char c)
{
	int i;

	i = 0;
	while(i < this->alphabet_size)
	{
		if (alphabet[i].find(c) != std::string::npos)
			return (i);
		i++;
	}
	return (i);
}

void Automata::set_string(const std::string& literal)
{
	this->str = literal;
}

void Automata::print_state()
{
	std::cout << "Estado: " << this->state << std::endl;
}

