# pragma once

# include <iostream>
# include <cstdlib>
# include <vector>


# define INT_MAX 2147483647
# define INT_MIN -2147483648


typedef std::vector<std::pair<int, int> > VecPairInt;
typedef std::pair<int, int> PairInt;
typedef std::vector<std::pair<int, int> >::iterator VectPairIntIter;



void pmergeme(int argc, char const *argv[]);
std::vector< std::pair<int, int> > create_fill_container(int argc, char const *argv[]);
void validate_number(char const *argv);
void print_vector(std::vector< std::pair<int, int> > vect);

void wololo(std::vector<std::pair<int, int> > &bigs);
void wololo(VecPairInt &bigs);
