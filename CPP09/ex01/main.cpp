# include "RPN.hpp"

int main(int argc, char *argv[])
{
	if (argc == 2 && argv[1][0] != '\0')
	{
		rpn(argv[1]);
	}
	else
	{
		std::cerr << "Error" << std::endl;
	}
	return 0;
}

void rpn(char *argv)
{
	std::stack<int> numbers;
	int i = 0;

	while (argv[i])
	{
		if ((argv[i] == '+' || argv[i] == '-' || argv[i] == '*' || argv[i] == '/')
			&& (argv[i + 1] == ' ' || argv[i + 1] == '\0'))
		{
			operation(numbers, argv[i]);
		}
		else if (argv[i] == '-' && (argv[i + 1] == ' ' || argv[i + 1] == '\0'))
		{
			operation(numbers, argv[i]);
		}
		else if (isdigit(argv[i]) == true && (argv[i + 1] == ' ' || argv[i + 1] == '\0'))
		{
			numbers.push(argv[i] - '0');
		}
		else if (argv[i] == '-' && isdigit(argv[i + 1]) 
			&& (argv[i + 2] == ' ' || argv[i + 2] == '\0'))
		{
			numbers.push((argv[i + 1] - '0') * (-1));
		}
		else if (argv[i] == ' ')
		{
			i++;
			continue;
		}
		else
		{
			print_input_error();
		}
		i++;
	}
	if (numbers.size() > 1)
	{
		std::cerr << "Error" << std::endl;
	}
	std::cout << numbers.top() << std::endl;
}

void operation(std::stack<int> &numbers, char symbol)
{
	int aux;

	if (numbers.size() <= 1)
	{
		print_input_error();
	}
	aux = numbers.top();
	numbers.pop();
	if (symbol == '+')
		aux = numbers.top() + aux;
	if (symbol == '*')
		aux = numbers.top() * aux;
	if (symbol == '-')
		aux = numbers.top() - aux;
	if (symbol == '/')
	{
		if (numbers.top() == 0)
		{
			print_input_error();
		}
		aux = numbers.top() / aux;
	}
	numbers.pop();
	numbers.push(aux);
	return;
}

void print_input_error(void)
{
	std::cerr << "Error" << std::endl;
	exit(EXIT_FAILURE);
}

void print_stack(std::stack<int> numbers)
{
	while (numbers.empty() == false)
	{
		std::cout << numbers.top() << " ";
		numbers.pop();
	}
	std::cout << std::endl;
}
