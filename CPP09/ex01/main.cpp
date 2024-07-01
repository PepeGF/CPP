# include "RPN.hpp"

int main(int argc, char *argv[])
{
    if (argc == 2 && argv[1][0] != '\0')
    {
        std::stack<int> numbers;
        std::stack<char> symbols;

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
        // parte push stack
        if ((argv[i] == '+' || argv[i] == '-' || argv[i] == '*' || argv[i] == '/')
            && (argv[i + 1] == ' ' || argv[i + 1] == '\0'))
        {
            operation(numbers, argv, i);
        }
        else if (isdigit(argv[i]) == true && (argv[i + 1] == ' ' || argv[i + 1] == '\0'))
        {
            numbers.push(argv[i] - '\0')
        }
        else if (argv[i] == '-' && argv[i + 1 ])
        // parte operadores


        // resto: errores
        i++;
    }
    if (numbers.size() > 1)
    {
        std::cout << "Invalid input, too amny numbers" << std::endl;
    }
}

