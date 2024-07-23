# pragma once

# include <iostream>
# include <cstdlib>
# include <vector>
# include <iomanip>


# define INT_MAX 2147483647
# define INT_MIN -2147483648


typedef std::vector<std::pair<int, int> > VecPairInt;
typedef std::pair<int, int> PairInt;
typedef std::vector<std::pair<int, int> >::iterator VectPairIntIter;



VecPairInt pmergeme(VecPairInt &vect);
VecPairInt create_fill_container(int argc, char const *argv[]);
void validate_number(char const *argv);
PairInt make_even(VecPairInt &bigger_sort);
void create_vectors(VecPairInt &bigger_sort,
					VecPairInt &bigger,
					VecPairInt &bigger_replica,
					VecPairInt &smaller,
					VecPairInt &smaller_replica);
void add_last_to_smaller(PairInt &last, 
						VecPairInt &smaller, 
						VecPairInt &smaller_replica);
VecPairInt recursivity(VecPairInt &bigger_sort, VecPairInt &bigger);
void sort_len_1(VecPairInt &bigger_replica, 
				VecPairInt &smaller_replica, 
				PairInt& last);
void insert_last_into_bigger(VecPairInt &bigger_replica, 
							VecPairInt &smaller_replica, 
						PairInt& last);
void replicate_changes(VecPairInt &bigger_sort, 
					VecPairInt &bigger, 
					VecPairInt &bigger_replica, 
					VecPairInt &smaller, 
					VecPairInt &smaller_replica, 
					PairInt &last);
VecPairInt insert_small_into_big(VecPairInt bigger_sort, 
								VecPairInt smaller_sort);
VecPairInt sort_with_insertion(VecPairInt &bigger_sort, 
							VecPairInt &bigger_replica, 
							VecPairInt &smaller, 
							VecPairInt &smaller_replica, 
							VecPairInt &smaller_sort, 
							PairInt &last);
void  binary_insertion(VecPairInt &bigger_sort, 
						PairInt x, 
						int idx_max, 
						int idx_min);


void print_vector(std::vector< std::pair<int, int> > vect);
void print_pair(PairInt pair);



void wololo(std::vector<std::pair<int, int> > &bigs);
void wololo(VecPairInt &bigs);
