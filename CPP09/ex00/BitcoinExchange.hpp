#pragma once

# include <map>
# include <iostream>
# include <fstream>
#include <cstdlib>

void    print_exchange(std::string input_file);
std::map<std::string, double> create_database();
void open_file(std::ifstream &file);
