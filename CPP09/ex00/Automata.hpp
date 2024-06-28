# pragma once
# include <iostream>

class Automata
	{
	private:
		// Attributes
		void		*data;
		int			alphabet_size;
		std::string	*alphabet;
		std::string	*errors;
		std::string	str;
		int			state;
		int			ostate;
		int			i;
		// int			j;

		// Methods
		int			(Automata::*state_function)(int, int);
		void		automata_init();
		int			set_state(int i, int j);
		int			evaluate();
		int			idx(std::string *alphabet, char c);

	public:
		Automata();
		Automata(void *data);
		~Automata();
		int		get_state();
		void	set_string(const std::string& str);
		void	print_state();
	};
