# pragma once

# include <iostream>
# include <cstdlib>
# include <vector>


# define INT_MAX 2147483647
# define INT_MIN -2147483648


typedef std::vector<std::pair<int, int> > VecPairInt;
typedef std::pair<int, int> PairInt;
typedef std::vector<std::pair<int, int> >::iterator VectPairIntIter;



VecPairInt pmergeme(VecPairInt &vect);
VecPairInt create_fill_container(int argc, char const *argv[]);
void validate_number(char const *argv);
PairInt make_even(VecPairInt &original);
void create_vectors(VecPairInt &original,
					VecPairInt &bigger,
					VecPairInt &bigger_replica,
					VecPairInt &smaller,
					VecPairInt &smaller_replica);
void add_last_to_smaller(PairInt &last, 
						VecPairInt &smaller, 
						VecPairInt &smaller_replica);
VecPairInt recursivity(VecPairInt &original, VecPairInt &bigger);

void print_vector(std::vector< std::pair<int, int> > vect);
void print_pair(PairInt pair);



void wololo(std::vector<std::pair<int, int> > &bigs);
void wololo(VecPairInt &bigs);
