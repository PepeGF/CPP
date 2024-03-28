# pragma once
# include <iostream>

class Automata
	{
	private:
		// Attributes
		// void		*data;
		int			alphabet_size;
		std::string	**alphabet;
		std::string	**errors;
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
		int			idx(std::string **alphabet, char c);

	public:
		Automata();
		~Automata();
		int		get_state();
		void	set_string(const std::string& str);
		void	print_state();
	};


// void	automata_init(t_automata *a);
// void	alphabet_init(t_automata *a);
// int		get_state(int i, int j);
// char 	**error_init(t_automata *a);
// int		evaluate(t_automata *a);
// int		idx(char *alphabet[], char c);

/* 
int main(int argc, char *argv[])
{
	t_automata	a;

	if (argc != 2)
		exit(1);
	ft_bzero(&a, sizeof(t_automata));
	automata_init(&a);
	a.str = argv[1];
	evaluate(&a);
	printf("Tipo: %d\n", a.state);
	ft_free_matrix(a.alphabet);
	return (0);
}

void	automata_init(t_automata *a)
{
	*a = (t_automata){};
	alphabet_init(a);
	error_init(a);
	// sactions_init(a);
	// tactions_init(a);
	a->get_state = get_state;
}

void alphabet_init(t_automata *a)
{
	a->alphabet = ft_sarradd(a->alphabet, "0123456789");
	a->alphabet = ft_sarradd(a->alphabet, ".");
	a->alphabet = ft_sarradd(a->alphabet, "f");
	a->alphabet = ft_sarradd(a->alphabet, "-");
}

int	get_state(int i, int j)
{
	int state[][6] = {
	//   #   .   f   -   ^
		{2,  3,  3,  1,  3}, // initial state	0
		{2,  6,  6,  6,  6}, // minus found		1
	    {2,  4,  5,  6,  6}, // int				2
		{6,  6,  6,  6,  6}, // char			3
		{4,  6,  5,  6,  6}, // double			4
		{6,  6,  6,  6,  6}, // float			5
		{6,  6,  6,  6,  6}  // string			6
	};
	return (state[i][j]);
}

char **error_init(t_automata *a)
{
	a->errors = NULL;
	return (a->errors);
}

int	evaluate(t_automata *a)
{
	int len;
	
	a->ostate = 0;
	a->i = 0;
	len = (int)ft_strlen(a->str);
	while (a->i < len)
	{
		a->state = a->get_state(a->state, idx(a->alphabet, a->str[a->i]));
		++(a->i);
	}
}

int idx(char *alphabet[], char c)
{
	int	i;

	i = 0;
	while(alphabet[i])
	{
		if (ft_strchr(alphabet[i], c) != NULL)
			return (i);
		i++;
	}
	return (i);
}
 */