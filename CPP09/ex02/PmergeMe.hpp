# pragma once

# include <iostream>
# include <cstdlib>
# include <vector>

# define INT_MAX 2147483647
# define INT_MIN -2147483648

void pmergeme(int argc, char const *argv[]);
void validate_number(char const *argv);
void print_vector(std::vector< std::pair<int, int> > vect);
