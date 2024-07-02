# pragma once

# include <iostream>
# include <stack>
# include <cctype>
# include <cstdlib>

void    rpn(char *argv);
void    print_input_error(void);
void    print_stack(std::stack<int> numbers);
void    operation(std::stack<int> &numbers, char symbol);
